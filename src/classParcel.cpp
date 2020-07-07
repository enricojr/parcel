#include "classParcel.hpp"
#include "defaults.hpp"
#include <cstdio>

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classParcel::classParcel(){
  init();
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classParcel::~classParcel(){
  size_.clear();
  position_.clear();
  orientation_.clear();
  wrapMaterial_.clear();
  wrapThickness_.clear();
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classParcel::init(){
  name_ = defaultValue::parcelName;
  type_ = defaultValue::parcelType;
  size_ = defaultValue::parcelSize;
  position_ = defaultValue::parcelPosition;
  orientation_ = defaultValue::parcelOrientation;
  material_ = defaultValue::parcelMaterial;
  return ;
}
  
/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classParcel::print() const{

  cout << endl;
  
  cout << __PRETTY_FUNCTION__ << ": name = " << name_ << endl;
  cout << __PRETTY_FUNCTION__ << ": type = " << type_ << endl;

  cout << __PRETTY_FUNCTION__ << ": size = (";
  for(unsigned int i=0; i<size_.size(); i++){
    if(i==0) cout << size_[i];
    else cout << ", " << size_[i];
  }
  cout << ")" << endl;

  cout << __PRETTY_FUNCTION__ << ": position = (";
  for(unsigned int i=0; i<position_.size(); i++){
    if(i==0) cout << position_[i];
    else cout << ", " << position_[i];
  }
  cout << ")" << endl;

  cout << __PRETTY_FUNCTION__ << ": orientation = (";
  for(unsigned int i=0; i<orientation_.size(); i++){
    if(i==0) cout << orientation_[i];
    else cout << ", " << orientation_[i];
  }
  cout << ")" << endl;

  cout << __PRETTY_FUNCTION__ << ": material = " << material_ << endl;

  if(wrapMaterial_.size() == 0){
    cout << __PRETTY_FUNCTION__ << ": wrap materials assigned - false" << endl;
  }
  else{
    cout << __PRETTY_FUNCTION__ << ": wrap materials assigned - true" << endl;
    cout << __PRETTY_FUNCTION__ << ": wrap materials =";
    for(unsigned int i=0; i<wrapMaterial_.size(); i++){
      cout << " " << wrapMaterial_[i];
    }
    cout << endl;
  }

  if(wrapThickness_.size() == 0){
    cout << __PRETTY_FUNCTION__ << ": wrap thicknesss assigned - false" << endl;
  }
  else{
    cout << __PRETTY_FUNCTION__ << ": wrap thicknesss assigned - true" << endl;
    cout << __PRETTY_FUNCTION__ << ": wrap thicknesss =";
    for(unsigned int i=0; i<wrapThickness_.size(); i++){
      cout << " " << wrapThickness_[i];
    }
    cout << endl;
  }

  return ;
}
  
/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

vector<double> classParcel::getPosition() const{
  return position_;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

vector<double> classParcel::getSize() const{
  return size_;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

string classParcel::getName() const{
  return name_;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classParcel::assignParameter(const string parameter,
				  const string value){

  if(parameter == "name"){
    name_ = value;
  }
  else if(parameter == "type"){
    type_ = value;
  }
  else if(parameter == "size"){
    vector<double> val(3, 0.);
    sscanf(value.c_str(), "%lf %lf %lf", &val[0], &val[1], &val[2]);
    size_ = val;
  }
  else if(parameter == "position"){
    vector<double> val(3, 0.);
    sscanf(value.c_str(), "%lf %lf %lf", &val[0], &val[1], &val[2]);
    position_ = val;
  }
  else if(parameter == "orientation"){
    vector<double> val(3, 0.);
    sscanf(value.c_str(), "%lf %lf %lf", &val[0], &val[1], &val[2]);
    orientation_ = val;
  }
  else if(parameter == "material"){
    material_ = value;
  }
  else if(parameter == "wrapMaterial"){
    stringstream value_ss;
    value_ss << value;
    string val = "";
    while(value_ss >> val){
      wrapMaterial_.push_back(val);
    }
  }
  else if(parameter == "wrapThickness"){
    stringstream value_ss;
    value_ss << value;
    double val = 0.;
    while(value_ss >> val){
      wrapThickness_.push_back(val);
    }
  }
  else{
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - undefined parameter: " << parameter << endl;
    return false;
  }
  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classParcel::check() const{

  if(wrapMaterial_.size() != wrapThickness_.size()){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - number of wrap materials doesn't match the number of wrap thicknesses" << endl;
    return false;
  }
  
  if(type_ != "box"){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - currently, only parcels of type box are allowed, unallowed type " << type_ << endl;
    return false;
  }

  if(!(orientation_[0]==0 && orientation_[1]==0 && orientation_[2]==0)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - currently, wrapped parcels cannot be rotated, i.e. the orientation vector must be (0,0,0)" << endl;
    return false;
  }
  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classParcel::build(ofstream &file) const{
  
  file << "############################################" << endl
       << "### parcel's main body" << endl << endl;
  
  file << "[" << name_ << "]" << endl;
  file << "type = " << type_ << endl;
  file << "material = " << material_ << endl;
  file << "size = "
       << size_[0] << "mm "
       << size_[1] << "mm "
       << size_[2] << "mm"
       << endl;
  file << "position = "
       << position_[0] << "mm "
       << position_[1] << "mm "
       << position_[2] << "mm"
       << endl;
  file << "orientation = "
       << orientation_[0] << "deg "
       << orientation_[1] << "deg "
       << orientation_[2] << "deg"
       << endl;

  if(!buildWrap(file)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot wrap parcel" << endl;
    return false;
  }  
  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classParcel::buildWrap(ofstream &file) const{

  if(wrapMaterial_.size() != 0){
    if(orientation_[0] != 0. || orientation_[1] != 0. || orientation_[2] != 0.){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - currently, only parcels with (0,0,0) orientation can be wrapped" << endl;
      return false;
    }
  }
  
  vector<double> effectiveParcelSize = size_;
  
  for(unsigned int i=0; i<wrapMaterial_.size(); i++){
    file << endl
	 << "############################################" << endl
	 << "### parcel's wrap layer " << i+1 << endl;

    // z+
    file << endl << "[parcelWrapLayer" << i+1 << "Top]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "size = "
	 << effectiveParcelSize[0]+2*wrapThickness_[i] << "mm "
	 << effectiveParcelSize[1]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] << "mm "
      	 << position_[2] + 0.5 * effectiveParcelSize[2] + 0.5 * wrapThickness_[i] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;

    // z-
    file << endl << "[parcelWrapLayer" << i+1 << "Bottom]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "size = "
	 << effectiveParcelSize[0]+2*wrapThickness_[i] << "mm "
	 << effectiveParcelSize[1]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] << "mm "
      	 << position_[2] - 0.5 * effectiveParcelSize[2] - 0.5 * wrapThickness_[i] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    // y+
    file << endl << "[parcelWrapLayer" << i+1 << "Left]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "size = "
	 << effectiveParcelSize[0]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm "
	 << effectiveParcelSize[2] << "mm"
      	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] + 0.5 * effectiveParcelSize[1] + 0.5 * wrapThickness_[i] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    // y-
    file << endl << "[parcelWrapLayer" << i+1 << "Right]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "size = "
	 << effectiveParcelSize[0]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm "
	 << effectiveParcelSize[2] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] - 0.5 * effectiveParcelSize[1] - 0.5 * wrapThickness_[i] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
        
    // x+
    file << endl << "[parcelWrapLayer" << i+1 << "Front]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "size = "
	 << wrapThickness_[i] << "mm "
	 << effectiveParcelSize[1] << "mm "
	 << effectiveParcelSize[2] << "mm"
	 << endl;
    file << "position = "
      	 << position_[0] + 0.5 * effectiveParcelSize[0] + 0.5 * wrapThickness_[i] << "mm "
	 << position_[1] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    // x-
    file << endl << "[parcelWrapLayer" << i+1 << "Back]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "size = "
	 << wrapThickness_[i] << "mm "
	 << effectiveParcelSize[1] << "mm "
	 << effectiveParcelSize[2] << "mm"
	 << endl;
    file << "position = "
      	 << position_[0] - 0.5 * effectiveParcelSize[0]- 0.5 * wrapThickness_[i] << "mm "
	 << position_[1] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    for(unsigned int j=0; j<effectiveParcelSize.size(); j++) effectiveParcelSize[j] += 2*wrapThickness_[i];
  }  
  
  return true;
}
