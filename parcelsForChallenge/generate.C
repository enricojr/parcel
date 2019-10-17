int writeSize(ofstream &file,
	      const string quantity){
  
  const string line50g = "size = 37 37 37";
  const string line100g = "size = 90 45 22.5";
  
  if(quantity == "50g"){
    file << line50g << endl;
  }
  else if(quantity == "100g"){
    file << line100g << endl;
  }
  else{
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - undefined quantity = " << quantity << endl;
    return 1;
  }
  
  return 0;
}

/************//************//************//************//************//************//************/
/************//************//************//************//************//************//************/

int buildParcel(const string flag,
		const string drug,
		const string quantity){

  const string fileNameCfg = "configs/material_" + flag + "_" + drug + "_" + quantity + ".cfg";
  ofstream file(fileNameCfg.c_str());
  
  file << "### parcel section start" << endl;
  file << "section = parcel" << endl;
  file << "name = parcel" << endl;
  file << "type = box" << endl;
  file << "size = 200 200 42" << endl;
  file << "position = 0 0 -79" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "material = air" << endl;
  file << "wrapMaterial = g4_cardboard" << endl;
  file << "wrapThickness = 0.4" << endl;
  file << "### parcel section end" << endl;
  file << endl;

  if(flag == "inAluminiumBox"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = aluminium" << endl;
    file << "wrapThickness = 1.0" << endl;
    file << "### drug section end" << endl;
  }
  else if(flag == "inPlasticBox"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_pet" << endl;
    file << "wrapThickness = 3.0" << endl;
    file << "### drug section end" << endl;
  }
  else if(flag == "nextToBrass"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_office_paper" << endl;
    file << "wrapThickness = 0.1" << endl;
    file << "### drug section end" << endl;
    file << endl;
    file << "### brass section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    file << "size = random gauss 10 10 10 2 2 2" << endl;
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = g4_brass" << endl;
    file << "### brass section end" << endl;
  }
  else if(flag == "nextToSteel"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_office_paper" << endl;
    file << "wrapThickness = 0.1" << endl;
    file << "### drug section end" << endl;
    file << endl;
    file << "### steel section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    file << "size = random gauss 20 150 2 2.0 15 0.2" << endl;
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = steel" << endl;
    file << "### steel section end" << endl;
  }
  else if(flag == "inLeather"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_collagen" << endl;
    file << "wrapThickness = 2.0" << endl;
    file << "### drug section end" << endl;
  }
  else if(flag == "inCotton"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_cellulose_cotton" << endl;
    file << "wrapThickness = 1.0" << endl;
    file << "### drug section end" << endl;
  }
  else if(flag == "inHeatShrink"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_ptfe" << endl;
    file << "wrapThickness = 0.3" << endl;
    file << "### drug section end" << endl;
  }
  else if(flag == "inMylar"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_pet" << endl;
    file << "wrapThickness = 0.1" << endl;
    file << "### drug section end" << endl;
  }
  else if(flag == "nextToLithium"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_office_paper" << endl;
    file << "wrapThickness = 0.1" << endl;
    file << "### drug section end" << endl;
    file << endl;
    file << "### steel section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    file << "size = random gauss 50 100 5 5.0 10 0.5" << endl;
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = lithium" << endl;
    file << "wrapMaterial = aluminium" << endl;
    file << "wrapThickness = 0.5" << endl;
    file << "### steel section end" << endl;
  }
  else if(flag == "nextToPCB"){
    file << "### drug section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    if(writeSize(file, quantity)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot write size" << endl;
      return 1;
    }
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = " << drug << endl;
    file << "wrapMaterial = g4_office_paper" << endl;
    file << "wrapThickness = 0.1" << endl;
    file << "### drug section end" << endl;
    file << endl;
    file << "### steel section start" << endl;
    file << "section = item" << endl;
    file << "name = drug" << endl;
    file << "type = box" << endl;
    file << "size = random gauss 50 100 2 5.0 10 0.2" << endl;
    file << "position = random uniform" << endl;
    file << "orientation = 0 0 0" << endl;
    file << "material = g4_circuit_board" << endl;
    file << "wrapMaterial = copper" << endl;
    file << "wrapThickness = 0.02" << endl;
    file << "### steel section end" << endl;
  }
  else{
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - undefined flag = " << flag << endl;
    return 1;
  }
  
  file.close();
  
  return 0;
}

/************//************//************//************//************//************//************/
/************//************//************//************//************//************//************/

int generate(){

  vector<string> flag;
  flag.push_back("inAluminiumBox"); // control sample: same mixes
  flag.push_back("inPlasticBox"); // control sample: same mixes
  flag.push_back("nextToBrass");
  flag.push_back("nextToSteel");
  flag.push_back("inLeather");
  flag.push_back("inCotton");
  flag.push_back("inHeatShrink");
  flag.push_back("inMylar");
  flag.push_back("nextToLithium");
  flag.push_back("nextToPCB");

  vector<string> drug;
  drug.push_back("air"); // control sample: harmless parcel
  drug.push_back("g4_benzyl_butyryl_fentanyl");
  drug.push_back("g4_benzyl_fentanyl");
  vector<pair<string, string> > ratio;
  ratio.push_back(pair<string, string> ("05", "95"));
  ratio.push_back(pair<string, string> ("10", "90"));
  ratio.push_back(pair<string, string> ("15", "85"));
  ratio.push_back(pair<string, string> ("20", "80"));
  ratio.push_back(pair<string, string> ("25", "75"));
  ratio.push_back(pair<string, string> ("30", "70"));
  ratio.push_back(pair<string, string> ("35", "65"));
  ratio.push_back(pair<string, string> ("40", "60"));
  ratio.push_back(pair<string, string> ("45", "55"));
  ratio.push_back(pair<string, string> ("50", "50"));
  vector<string> mix1;
  mix1.push_back("bbf");
  mix1.push_back("bf");
  vector<string> mix2;
  mix2.push_back("l");
  mix2.push_back("bs");
  mix2.push_back("a");
  for(unsigned int iRatio=0; iRatio<ratio.size(); iRatio++){
    for(unsigned int iMix1=0; iMix1<mix1.size(); iMix1++){
      for(unsigned int iMix2=0; iMix2<mix2.size(); iMix2++){
	string name = "g4_" + mix1[iMix1] + ratio[iRatio].first + mix2[iMix2] + ratio[iRatio].second;
	drug.push_back(name);
      }
    }
  }

  vector<string> quantity;
  quantity.push_back("50g");
  quantity.push_back("100g");

  for(unsigned int iFlag=0; iFlag<flag.size(); iFlag++){
    for(unsigned int iDrug=0; iDrug<drug.size(); iDrug++){
      for(unsigned int iQuantity=0; iQuantity<quantity.size(); iQuantity++){
	if(buildParcel(flag[iFlag], drug[iDrug], quantity[iQuantity])){
	  cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot build parcel " << flag[iFlag] << ", " << drug[iDrug] << ", " << quantity[iQuantity] << endl;
	  return 1;
	}
      }
    }
  }
  
  return 0;
}
