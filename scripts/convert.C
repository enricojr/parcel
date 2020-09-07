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
  if(Z==33) return "As";
  if(Z==35) return "Br";
  if(Z==50) return "50";
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

void uncapitalize(char *name){

  for(unsigned int i=0; i<1000; i++){
    if(name[i]>=65 && name[i]<=90) name[i]+=32;
  }
  
  return ;
}

/*************************************************************************************/
/*************************************************************************************/
/*************************************************************************************/

int parseMaterials(ofstream &fileOut, ofstream &fileOut2, ofstream &fileOut3, ofstream &fileOut4,
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
    for(unsigned int iElement=0; iElement<nElements; iElement++){
      unsigned int Z;
      double nAtoms;
      getline(fileIn, line);      
      sscanf(line.c_str(), "%d\t%lf", &Z, &nAtoms);
      fileOut << name << "->AddElement(" << getElement(Z) << ", " << nAtoms << ");" << endl;
    }
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
  //  fileName.push_back(pair<string, string> ("Drugs_Library.txt", "DRUGS"));
  //  fileName.push_back(pair<string, string> ("Explosives_Library.txt", "EXPLOSIVES"));
  //  fileName.push_back(pair<string, string> ("Other_library.txt", "OTHERS"));
  //  fileName.push_back(pair<string, string> ("UXO.txt", "UXO"));
  //  fileName.push_back(pair<string, string> ("Explosives_Libraryv2.txt", "EXPLOSIVES")); // new from 2020-08-29 after bug fix
  //  fileName.push_back(pair<string, string> ("Other_libraryv2.txt", "OTHERS")); // new from 2020-08-29 after bug fix
  //  fileName.push_back(pair<string, string> ("Shielding_Materialsv2.txt", "SHIELDING"));
  //  fileName.push_back(pair<string, string> ("Shielding_Materialsv3.txt", "SHIELDING"));
  fileName.push_back(pair<string, string> ("Shielding_Materialsv4.txt", "SHIELDING"));
  
  ofstream fileOut("commands.txt");
  ofstream fileOut2("commands2.txt");
  ofstream fileOut3("../standalone/templates/analysis/loopMaterials");
  ofstream fileOut4("commands3.txt");
  
  for(unsigned int i=0; i<fileName.size(); i++){
    parseMaterials(fileOut, fileOut2, fileOut3, fileOut4, fileName[i]);        
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
