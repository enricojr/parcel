#include <iostream>
#include <fstream>
using namespace std;

string getElement(const unsigned int Z){
  if(Z==1) return "H";
  if(Z==2) return "He";
  if(Z==3) return "Li";
  if(Z==4) return "Be";
  if(Z==5) return "B";
  if(Z==6) return "C";
  if(Z==7) return "N";
  if(Z==8) return "O";
  if(Z==9) return "F";
  if(Z==10) return "Ne";
  if(Z==11) return "Na";
  if(Z==12) return "Mg";
  if(Z==13) return "Al";
  if(Z==14) return "Si";
  if(Z==15) return "P";
  if(Z==16) return "S";
  if(Z==17) return "Cl";
  if(Z==18) return "Ar";
  if(Z==19) return "K";
  if(Z==20) return "Ca";
  if(Z==21) return "Sc";
  if(Z==22) return "Ti";
  if(Z==23) return "V";
  if(Z==24) return "Cr";
  if(Z==25) return "Mn";
  if(Z==26) return "Fe";
  if(Z==27) return "Co";
  if(Z==28) return "Ni";
  if(Z==29) return "Cu";
  if(Z==33) return "As";
  if(Z==35) return "Br";
  if(Z==42) return "Mo";
  if(Z==50) return "Sn";
  if(Z==53) return "I";
  if(Z==56) return "Ba";
  if(Z==73) return "Ta";
  if(Z==82) return "Pb";
  if(Z==83) return "Bi";
  if(Z==1010) return "B10";
  if(Z==1011) return "B11";
  else{
    cout << "WARNING!!! ADD NEW ELEMENT TO THE DATABASE, WITH Z = " << Z << endl;
    return "";
  }
}

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

double getMass(const unsigned int Z){
  if(Z==1) return 1.008;
  if(Z==2) return 4.0026;
  if(Z==3) return 6.94;
  if(Z==4) return 9.0122;
  if(Z==5) return 10.81;
  if(Z==6) return 12.011;
  if(Z==7) return 14.007;
  if(Z==8) return 15.999;
  if(Z==9) return 18.998;
  if(Z==10) return 20.180;
  if(Z==11) return 22.990;
  if(Z==12) return 24.305;
  if(Z==13) return 26.982;
  if(Z==14) return 28.085;
  if(Z==15) return 30.974;
  if(Z==16) return 32.06;
  if(Z==17) return 35.45;
  if(Z==18) return 39.948;
  if(Z==19) return 39.098;
  if(Z==20) return 40.078;
  if(Z==21) return 44.956;
  if(Z==22) return 47.867;
  if(Z==23) return 50.942;
  if(Z==24) return 51.996;
  if(Z==25) return 54.938;
  if(Z==26) return 55.845;
  if(Z==27) return 58.933;
  if(Z==28) return 58.693;
  if(Z==29) return 63.546;
  if(Z==33) return 74.922;
  if(Z==35) return 79.904;
  if(Z==42) return 95.95;
  if(Z==50) return 118.71;
  if(Z==53) return 126.90;
  if(Z==56) return 137.33;
  if(Z==73) return 180.95;
  if(Z==82) return 207.2;
  if(Z==83) return 208.98;
  if(Z==1010) return 10.;
  if(Z==1011) return 11.;
  else{
    cout << "WARNING!!! ADD NEW ELEMENT TO THE DATABASE, WITH Z = " << Z << endl;
    return 0.;
  }
}

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

void uncapitalize(char *name){

  for(unsigned int i=0; i<1000; i++){
    if(name[i]>=65 && name[i]<=90) name[i]+=32;
  }
  
  return ;
}

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

int parseMaterials(ofstream &fileOut, ofstream &fileOut2, ofstream &fileOut3, ofstream &fileOut4, ofstream &fileOut5,
		   const pair<string, string> fileName){

  fileOut << "/////////////////////////////////////////////////////////" << endl;
  fileOut << "// " << fileName.second << endl;
  fileOut << "/////////////////////////////////////////////////////////" << endl;

  ifstream fileIn(fileName.first.c_str());

  string line = "";
  unsigned int nElements = 0;
  char name[1000];
  double density = 0.;
  double ionizationPotential = 0.;
  char formula[1000];
  
  getline(fileIn, line);
  getline(fileIn, line);
  getline(fileIn, line);

  fileOut3 << "#!/bin/bash" << endl;
  
  while(getline(fileIn, line)){
    sscanf(line.c_str(), "%d\t%s\t%lf\t%lf\t%s", &nElements, name, &density, &ionizationPotential, formula);
    uncapitalize(name);
    fileOut << endl << "// Create " << name << endl;
    fileOut << "G4Material* " << name << " = new G4Material(\"" << name << "\", " << density << " * CLHEP::g / CLHEP::cm3, " << nElements << ");" << endl;
    double effectiveZ = 0.;
    double nElectrons = 0.;
    for(unsigned int iElement=0; iElement<nElements; iElement++){
      unsigned int Z;
      double nAtoms;
      getline(fileIn, line);      
      sscanf(line.c_str(), "%d\t%lf", &Z, &nAtoms);
      fileOut << name << "->AddElement(" << getElement(Z) << ", " << nAtoms << ");" << endl;
      if(nAtoms < 1.) nAtoms /= getMass(Z);      
      nElectrons += (nAtoms * Z);
      effectiveZ += (nAtoms * Z * pow(Z, 2.94));
      if(strcmp(name, "hdpe") == 0) cout << name << ", Z=" << getElement(Z) << ", nAtoms=" << nAtoms << ", mass=" << getMass(Z) << ", nElectrons = " << nAtoms * Z << endl;
    }

    effectiveZ = pow(effectiveZ / nElectrons, 1./2.94);
    fileOut5 << name << ", " << formula << ", " << effectiveZ << endl;
    
    fileOut << "materials_[\"" << name <<  "\"] = " << name << ";" << endl;
    fileOut2 << "density.push_back(" << density << ");  material.push_back(\"" << name << "\");" << endl;
    
    fileOut3 << "root -b << EOF" << endl;
    fileOut3 << ".L analyzeLoop.C++" << endl;
    fileOut3 << "analyzeLoop(\"" << name << "\")" << endl;
    fileOut3 << "EOF" << endl;

    fileOut4 << "\\includegraphics[width=0.3\\textwidth]{figures/templates/h1GammaEnergy_" << name << ".pdf}" << endl;
  }

  fileIn.close();
  
  fileOut << endl;

  return 0;
}

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

void makeElements(ofstream &file){
  
  vector<string> material;
  material.push_back("g4_hydrogen");
  material.push_back("g4_helium");
  material.push_back("g4_lithium");
  material.push_back("g4_berillium");
  material.push_back("g4_boron");
  material.push_back("g4_carbon");
  material.push_back("g4_nitrogen");
  material.push_back("g4_oxygen");
  material.push_back("g4_fluorine");
  material.push_back("g4_neon");
  material.push_back("g4_sodium");
  material.push_back("g4_magnesium");
  material.push_back("g4_aluminium");
  material.push_back("g4_silicon");
  material.push_back("g4_phosphor");
  material.push_back("g4_sulfur");
  material.push_back("g4_clorine");
  material.push_back("g4_argon");
  material.push_back("g4_potassium");
  material.push_back("g4_calcium");
  material.push_back("g4_scandium");
  material.push_back("g4_titanium");
  material.push_back("g4_vanadium");
  material.push_back("g4_cromium");
  material.push_back("g4_manganese");
  material.push_back("g4_iron");
  material.push_back("g4_cobalt");
  material.push_back("g4_nickel");
  material.push_back("g4_copper");
  material.push_back("g4_zinc");
  material.push_back("g4_gallium");
  material.push_back("g4_germanium");
  material.push_back("g4_arsenicum");
  material.push_back("g4_selenium");
  material.push_back("g4_bromine");
  material.push_back("g4_kripton");
  material.push_back("g4_rubidium");
  material.push_back("g4_strontium");
  material.push_back("g4_yttrium");
  material.push_back("g4_zirconium");
  material.push_back("g4_niobium");
  material.push_back("g4_molibdenum");
  material.push_back("g4_technetium");
  material.push_back("g4_ruthenium");
  material.push_back("g4_rhodium");
  material.push_back("g4_palladium");
  material.push_back("g4_silver");
  material.push_back("g4_cadmium");
  material.push_back("g4_indium");
  material.push_back("g4_tin");
  material.push_back("g4_antimonium");
  material.push_back("g4_tellurium");
  material.push_back("g4_iodine");
  material.push_back("g4_xenon");
  material.push_back("g4_cesium");
  material.push_back("g4_barium");
  material.push_back("g4_lantanium");
  material.push_back("g4_tungsten");
  material.push_back("g4_platinum");
  material.push_back("g4_gold");
  material.push_back("g4_mercury");
  material.push_back("g4_lead");
  material.push_back("g4_uranium");

  file << "#!/bin/bash" << endl;
  for(unsigned int i=0; i<material.size(); i++){
    file << "root -b << EOF" << endl;
    file << ".L analyzeLoop.C++" << endl;
    file << "analyzeLoop(\"" << material[i] << "\")" << endl;
    file << "EOF" << endl;
  }

  return ;
}

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

int convert(){

  vector<pair<string, string> > fileName;
  // fileName.push_back(pair<string, string> ("Drugs_Library.txt", "DRUGS"));
  // fileName.push_back(pair<string, string> ("Explosives_Library.txt", "EXPLOSIVES"));
  // fileName.push_back(pair<string, string> ("Other_library.txt", "OTHERS"));
  // fileName.push_back(pair<string, string> ("UXO.txt", "UXO"));
  // fileName.push_back(pair<string, string> ("Explosives_Libraryv2.txt", "EXPLOSIVES")); // new from 2020-08-29 after bug fix
  // fileName.push_back(pair<string, string> ("Other_libraryv2.txt", "OTHERS")); // new from 2020-08-29 after bug fix
  // fileName.push_back(pair<string, string> ("Shielding_Materialsv2.txt", "SHIELDING"));
  // fileName.push_back(pair<string, string> ("Shielding_Materialsv3.txt", "SHIELDING"));
  // fileName.push_back(pair<string, string> ("Shielding_Materialsv4.txt", "SHIELDING"));
  // fileName.push_back(pair<string, string> ("Steels.txt", "STEELS"));
  // fileName.push_back(pair<string, string> ("Starfire.txt", "STARFIRE"));
  //  fileName.push_back(pair<string, string> ("Showergel.txt", "OTHERS"));
  //  fileName.push_back(pair<string, string> ("BasaltSoil.txt", "SOIL"));
  // fileName.push_back(pair<string, string> ("Milk.txt", ""));
  // fileName.push_back(pair<string, string> ("Glucose.txt", ""));
  // fileName.push_back(pair<string, string> ("Flour.txt", ""));
  // fileName.push_back(pair<string, string> ("Cookies.txt", ""));
  // fileName.push_back(pair<string, string> ("Chocolate.txt", ""));
  // fileName.push_back(pair<string, string> ("Butter.txt", ""));
  // fileName.push_back(pair<string, string> ("Update_Feb2021.txt", ""));
  // fileName.push_back(pair<string, string> ("Cake.txt", ""));
  fileName.push_back(pair<string, string> ("Cell_18650.txt", ""));
  
  ofstream fileOut("commands.txt");
  ofstream fileOut2("commands2.txt");
  ofstream fileOut3("../standalone/templates/analysis/loopMaterials");
  ofstream fileOut4("commands3.txt");
  ofstream fileOut5("effectiveAtomicNumber.csv");
  
  for(unsigned int i=0; i<fileName.size(); i++){
    parseMaterials(fileOut, fileOut2, fileOut3, fileOut4, fileOut5, fileName[i]);        
  }
  
  fileOut.close();
  fileOut2.close();
  fileOut3.close();
  fileOut4.close();

  ofstream fileOut3bis("../standalone/templates/analysis/loopElements");
  makeElements(fileOut3bis);  
  fileOut3bis.close();
  
  return 0;
}
