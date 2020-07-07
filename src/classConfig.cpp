#include "classConfig.hpp"

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classConfig::classConfig(const string fileNameIn,
			 const string fileNameOut){
  init(fileNameIn, fileNameOut);
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classConfig::~classConfig(){
  if(parcel_ != NULL) delete parcel_;
  for(unsigned int i=0; i<item_.size(); i++){
    delete item_[i];
  }
  item_.clear();
  for(unsigned int i=0; i<itemSet_.size(); i++){
    delete itemSet_[i];
  }
  itemSet_.clear();
  delete random_;
  delete volumeLogger_;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classConfig::init(const string fileNameIn,
		       const string fileNameOut){

  fileNameIn_ = fileNameIn;
  fileNameOut_ = fileNameOut;

  parcel_ = NULL;
  
  debug_ = false;

  random_ = new classRandom();

  volumeLogger_ = new classVolumeLogger();

  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classConfig::print() const{

  cout << endl << __PRETTY_FUNCTION__ << ": =============================================================== START SECTIONS LIST" << endl << endl;
  
  cout << __PRETTY_FUNCTION__ << ": fileNameIn = " << fileNameIn_ << endl;
  cout << __PRETTY_FUNCTION__ << ": fileNameOut = " << fileNameOut_ << endl;
  if(parcel_ != NULL){
    cout << __PRETTY_FUNCTION__ << ": parcel assigned - true" << endl;
    parcel_ -> print();
  }
  else cout << __PRETTY_FUNCTION__ << ": parcel assigned - false" << endl;
  for(unsigned int i=0; i<item_.size(); i++){
    cout << __PRETTY_FUNCTION__ << ": item assigned - true" << endl;
    item_[i] -> print();
  }
  for(unsigned int i=0; i<itemSet_.size(); i++){
    cout << __PRETTY_FUNCTION__ << ": item set assigned - true" << endl;
    itemSet_[i] -> print();
  }

  cout << endl << __PRETTY_FUNCTION__ << ": =============================================================== END SECTIONS LIST" << endl << endl;
  
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classConfig::findNextSection(ifstream &file){

  string line = "";
  while(getline(file, line)){
    if(debug_) cout << __PRETTY_FUNCTION__ << ": DEBUG: " << line << endl;
    if(line[0] == '#'){
      cout << __PRETTY_FUNCTION__ << ": found new section: " << line << endl;
      return true;
    }
  }
  
  return false;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classConfig::loadParcel(ifstream &file){

  if(parcel_ != NULL){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - parcel already exists, cannot load a new one, check for multiple definitions in the configuration file" << endl;
    return false;
  }
  else parcel_ = new classParcel();

  string line = "";
  while(getline(file, line)){
    if(debug_) cout << __PRETTY_FUNCTION__ << ": DEBUG: " << line << endl;
    if(line[0] == '#') break;
    const unsigned int center = line.find(" = ");
    string parameter = line.substr(0, center);
    string value = line.substr(center+3, line.size());
    if(!parcel_ -> assignParameter(parameter, value)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << parameter << " = " << value << endl;
      return false;
    }
  }
  
  if(parcel_ -> check()) return true;
  else{
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - parcel consistency check failed" << endl;
    return false;
  }
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classConfig::loadItem(ifstream &file){

  classItem *item = new classItem(random_, volumeLogger_);
  
  string line = "";
  while(getline(file, line)){
    if(debug_) cout << __PRETTY_FUNCTION__ << ": DEBUG: " << line << endl;
    if(line[0] == '#') break;
    const unsigned int center = line.find(" = ");
    string parameter = line.substr(0, center);
    string value = line.substr(center+3, line.size());
    if(!item -> assignParameter(parameter, value, parcel_ -> getPosition(), parcel_ -> getSize())){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << parameter << " = " << value << endl;
      return false;
    }
  }

  item_.push_back(item);

  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classConfig::loadItemSet(ifstream &file){

  classItemSet *itemSet = new classItemSet(random_, volumeLogger_);
  
  string line = "";
  while(getline(file, line)){
    if(debug_) cout << __PRETTY_FUNCTION__ << ": DEBUG: " << line << endl;
    if(line[0] == '#') break;
    const unsigned int center = line.find(" = ");
    string parameter = line.substr(0, center);
    string value = line.substr(center+3, line.size());
    if(!itemSet -> assignParameter(parameter, value, parcel_ -> getPosition(), parcel_ -> getSize())){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << parameter << " = " << value << endl;
      return false;
    }
  }

  itemSet_.push_back(itemSet);

  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classConfig::identifySection(const string line,
				  string &name){

  char sectionName[100];
  sscanf(line.c_str(), "section = %s", sectionName);
  stringstream sectionName_ss;
  sectionName_ss << sectionName;
  name = sectionName_ss.str();
  if(name == "parcel" || name == "item" || name == "itemSet"){
    cout << __PRETTY_FUNCTION__ << ": section identified with name " << name << endl;
    return true;
  }
  else{
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - unidentified section type = " << name << endl;
    cout << __PRETTY_FUNCTION__ << ": here are the possible causes: " << endl;
    cout << __PRETTY_FUNCTION__ << ": 1) the section type is really not defined (yet) " << endl;
    cout << __PRETTY_FUNCTION__ << ": 2) the configuration file has a typo, remember that the correct syntax is" << endl;
    cout << __PRETTY_FUNCTION__ << ":    # anything" << endl;
    cout << __PRETTY_FUNCTION__ << ":    section = <sectionName>" << endl;
    return false;
  }
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

int classConfig::loadSection(ifstream &file){

  string line = "";
  while(getline(file, line)){
    if(debug_) cout << __PRETTY_FUNCTION__ << ": DEBUG: " << line << endl;
    string sectionName = "";
    if(!identifySection(line, sectionName)) return 1;
    if(sectionName == "parcel"){
      if(!loadParcel(file)){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot load parcel" << endl;
	return 2;
      }
      else return 0;
    }
    else if(sectionName == "item"){
      if(parcel_ == NULL){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot load items if a parcel is not defined yet; the item needs to be placed relative to the parcel position" << endl;
	return 1;
      }
      if(!loadItem(file)){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot load item" << endl;
	return 2;
      }
      else return 0;
    }
    else if(sectionName == "itemSet"){
      if(parcel_ == NULL){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot load items if a parcel is not defined yet; the item needs to be placed relative to the parcel position" << endl;
	return 1;
      }
      if(!loadItemSet(file)){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot load item set" << endl;
	return 2;
      }
      else return 0;
    }
    else{
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - (yet) undefined section name = " << sectionName << endl;
      return 1;
    }
  }
  
  return 0;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

int classConfig::load(){

  ifstream file(fileNameIn_.c_str());
  if(!file){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot open file " << fileNameIn_ << endl;
    return 1;
  }

  string line = "";

  int returnCode = 0;

  while(true){
    if(findNextSection(file)){
      returnCode = loadSection(file);
      if(returnCode != 0) break;
    }
    else{
      returnCode = 0;
      break;
    }
  }
  
  file.close();  
  return returnCode;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classConfig::check() const{
  if(parcel_ == NULL) return false;
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classConfig::buildSetup(ofstream &file){
  file << "############################################" << endl;
  file << "### setup" << endl;
  file << "" << endl;    
  file << "[Lithium_target]" << endl;
  file << "type = box" << endl;
  file << "size = 50mm 50mm 2mm" << endl;
  file << "material = vacuum" << endl;
  file << "position = 0mm 0mm 0mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[accelerator]" << endl;
  file << "type = box" << endl;
  file << "size = 134mm 134mm 2000mm" << endl;
  file << "material = copper" << endl;
  file << "position = 0mm 0mm 1012mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[conveyer_belt]" << endl;
  file << "type = box" << endl;
  file << "size = 10000mm 700mm 6mm" << endl;
  file << "material = g4_light_steel" << endl;
  file << "position = 0mm 0mm -353mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[support]" << endl;
  file << "type = box" << endl;
  file << "size = 200mm 200mm 6mm" << endl;
  file << "material = g4_light_steel" << endl;
  file << "position = 0mm 0mm -103mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[support_pillar1]" << endl;
  file << "type = box" << endl;
  file << "size = 6mm 6mm 244mm" << endl;
  file << "material = steel" << endl;
  file << "position = 100mm 100mm -228mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[support_pillar2]" << endl;
  file << "type = box" << endl;
  file << "size = 6mm 6mm 244mm" << endl;
  file << "material = steel" << endl;
  file << "position = 100mm -100mm -228mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[support_pillar3]" << endl;
  file << "type = box" << endl;
  file << "size = 6mm 6mm 244mm" << endl;
  file << "material = steel" << endl;
  file << "position = -100mm 100mm -228mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[support_pillar4]" << endl;
  file << "type = box" << endl;
  file << "size = 6mm 6mm 244mm" << endl;
  file << "material = steel" << endl;
  file << "position = -100mm -100mm -228mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;

  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

int classConfig::build(const bool fullSetup){

  ofstream file(fileNameOut_.c_str());
  if(!file){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot open file " << fileNameOut_ << endl;
    return 1;
  }

  if(fullSetup) buildSetup(file);
  
  if(parcel_ != NULL){
    cout << __PRETTY_FUNCTION__ << ": building parcel" << endl;
    if(!parcel_ -> build(file)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot build parcel" << endl;
      return 1;
    }
  }
  else{
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - parcel configuration is missing, didn't you run classConfig::check() ???" << endl;
    return 1;
  }

  for(unsigned int i=0; i<item_.size(); i++){
    cout << __PRETTY_FUNCTION__ << ": building item #" << i+1 << endl;
    if(!item_[i] -> build(file, parcel_ -> getName())){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot build item #" << i+1 << endl;
      return 1;
    }
  }
  
  for(unsigned int i=0; i<itemSet_.size(); i++){
    cout << __PRETTY_FUNCTION__ << ": building item set #" << i+1 << endl;
    if(!itemSet_[i] -> build(file, parcel_ -> getName())){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot build item set #" << i+1 << endl;
      return 1;
    }
  }
  
  file.close();
  
  return 0;
}
