#include "classRandom.hpp"
#include "classVolumeLogger.hpp"
#include "classItem.hpp"
#include "defaults.hpp"
#include <cstdio>

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classItem::classItem(classRandom *random,
		     classVolumeLogger *volumeLogger){
  random_ = random;
  volumeLogger_ = volumeLogger;
  init();
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classItem::~classItem(){
  size_.clear();
  position_.clear();
  orientation_.clear();
  wrapMaterial_.clear();
  wrapThickness_.clear();
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classItem::init(){
  name_ = defaultValue::itemName;
  type_ = defaultValue::itemType;
  size_ = defaultValue::itemSize;
  position_ = defaultValue::itemPosition;
  orientation_ = defaultValue::itemOrientation;
  material_ = defaultValue::itemMaterial;
  return ;
}
  
/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classItem::print() const{

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

bool classItem::checkSize(const vector<double> motherSize,
			  const vector<double> mean,
			  const vector<double> sigma) const{

  bool tooLarge = false;

  for(unsigned int i=0; i<3; i++){
    if(mean[i] + 3.*sigma[i] > motherSize[i]){
      cout << __PRETTY_FUNCTION__ << ": WARNING!!! dimension " << i+1 << " is too close to the mother volume dimension" << endl;
      tooLarge = true;
    }
  }
  
  return !tooLarge;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItem::generatePositionUniform(const vector<double> motherSize){

  for(unsigned int i=0; i<3; i++){
    const double min = - 0.5 * motherSize[i] + 0.5 * size_[i];
    const double max = 0.5 * motherSize[i] - 0.5 * size_[i];
    if(min > max){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - item named " << name_ << " is too large" << endl;
      return false;
    }
    position_[i] = random_ -> generateRandomUniform(min, max);
  }  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classItem::generateOrientationUniform(){

  for(unsigned int i=0; i<3; i++){
    const double min = -180.;
    const double max = +180.;
    orientation_[i] = random_ -> generateRandomUniform(min, max);
  }
  
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classItem::generateSizeGaussian(const vector<double> mean,
				     const vector<double> sigma){

  for(unsigned int i=0; i<3; i++){
    size_[i] = random_ -> generateRandomGauss(mean[i], sigma[i]);
  }
  
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItem::doesNotFit(const vector<double> motherSize) const{

  for(unsigned int i=0; i<3; i++){
    if(size_[i] > motherSize[i]){
      return true;
    }
  }
  
  return false;
}
  
/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItem::isANumber(const char character) const{
  if(character == 43) return true; // +
  else if(character == 45) return true; // -
  else if(character == 46) return true; // .
  if(character >= 48 && character <= 57) return true; // 0-9
  else return false;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

double classItem::computeRadius() const{
  double radius = -1.;
  for(unsigned int i=0; i<3; i++){
    double effectiveSize = size_[i];
    for(unsigned int j=0; j<wrapThickness_.size(); j++){
      effectiveSize+= wrapThickness_[j];
    }
    if(size_[i] > radius) radius = effectiveSize;
  }
  return radius;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classItem::shiftPosition(const vector<double> origin){
  for(unsigned int i=0; i<3; i++){
    position_[i] += origin[i];
  }
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItem::assignParameter(const string parameter,
				const string value,
				const vector<double> origin,
				const vector<double> motherSize){

  stringstream value_ss;
  value_ss << value;  
  string first = "";
  value_ss >> first;
  string second = "";
  value_ss >> second;
    
  if(parameter == "name"){
    name_ = value;
  }
  else if(parameter == "type"){
    type_ = "pill"; // WARNING!!! HARDCODED VALUE. The type of any object inside the parcel must be "pill", as of 2019-09-23, pending further developments in Allpix²
  }
  else if(parameter == "size"){
    if(first == "random"){
      if(second == "gauss"){
	vector<double> mean(3, 0.);
	vector<double> sigma(3, 0.);
	sscanf(value.c_str(), "random gauss %lf %lf %lf %lf %lf %lf", &mean[0], &mean[1], &mean[2], &sigma[0], &sigma[1], &sigma[2]);
	if(!checkSize(motherSize, mean, sigma)){
	  cout << __PRETTY_FUNCTION__ << ": WARNING!!! - one or more dimensions of this item might be close to the mother volume dimensions. This may slow down the item generation. Consider resizing this item, or giving it a fixed size." << endl;
	  return false;
	}
	unsigned int nAttempts = 1;
	generateSizeGaussian(mean, sigma);
	while(doesNotFit(motherSize)){
	  nAttempts ++;
	  generateSizeGaussian(mean, sigma);
	  if(nAttempts > defaultValue::itemMaxAttemptsSize){
	    cout << __PRETTY_FUNCTION__ << ": WARNING!!! - reached maximum number of attempts (" << defaultValue::itemMaxAttemptsSize << ") to generate random size. The item named " << name_ << " will not be allocated." << endl;
	    return true;
	  }
	  else continue;
	}
	cout << __PRETTY_FUNCTION__ << ": number of attempts to generate random size = " << nAttempts << endl;
      }
      else{
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - (yet) undefined random generator for size parameter = " << second << endl;
	return false;
      }
    }
    else if(!isANumber(first[0])){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - invalid value (or not implemented yet) for size parameter = " << value << endl;
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - please check the syntax" << endl;
      return false;
    }
    else{
      vector<double> val(3, 0.);
      sscanf(value.c_str(), "%lf %lf %lf", &val[0], &val[1], &val[2]);
      size_ = val;
    }
  }
  else if(parameter == "position"){

    const double radius = computeRadius();
    
    if(first == "center"){
      position_ = vector<double>(3, 0.);
      if(!volumeLogger_ -> spaceIsFree(position_, radius)){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - item named " << name_ << " cannot be placed, overlapping with other items" << endl;
	return false;
      }
    }
    else if(first == "random"){      
      if(second == "uniform"){
	unsigned int nAttempts = 1;
	if(!generatePositionUniform(motherSize)){
	  cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot generate random position for item named " << name_ << endl;
	  return false;
	}
	while(!volumeLogger_ -> spaceIsFree(position_, radius)){
	  nAttempts ++;
	  generatePositionUniform(motherSize);
	  if(nAttempts > defaultValue::itemMaxAttemptsPosition){
	    cout << __PRETTY_FUNCTION__ << ": WARNING!!! - reached maximum number of attempts (" << defaultValue::itemMaxAttemptsPosition << ") to generate random position. The item named " << name_ << " will not be allocated." << endl;
	    return true;
	  }	
	  else continue;	
	}
	cout << __PRETTY_FUNCTION__ << ": number of attempts to generate random position = " << nAttempts << endl;
      }
      else{
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - (yet) undefined random generator for position parameter = " << second << endl;
	return false;
      }
    }
    else if(!isANumber(first[0])){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - invalid value (or not implemented yet) for position parameter = " << value << endl;
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - please check the syntax" << endl;
      return false;
    }
    else{
      vector<double> val(3, 0.);
      sscanf(value.c_str(), "%lf %lf %lf", &val[0], &val[1], &val[2]);
      position_ = val;
      if(!volumeLogger_ -> spaceIsFree(position_, radius)){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - item named " << name_ << " cannot be placed, overlapping with other items" << endl;
	return false;
      }
    }
    volumeLogger_ -> addBubble(position_, radius);
  }
  else if(parameter == "orientation"){
    if(first == "random"){
      if(second == "uniform"){
	generateOrientationUniform();
      }
      else{
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - (yet) undefined random generator for orientation parameter = " << second << endl;
	return false;
      }
    }
    else if(!isANumber(first[0])){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - invalid value (or not implemented yet) for orientation parameter = " << value << endl;
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - please check the syntax" << endl;
      return false;
    }
    else{
      vector<double> val(3, 0.);
      sscanf(value.c_str(), "%lf %lf %lf", &val[0], &val[1], &val[2]);
      orientation_ = val;
    }
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

bool classItem::check() const{

  if(wrapMaterial_.size() != wrapThickness_.size()){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - number of wrap materials doesn't match the number of wrap thicknesses" << endl;
    return false;
  }
  
  if(type_ != "box"){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - currently, only items of type box are allowed, unallowed type " << type_ << endl;
    return false;
  }

  if(!(orientation_[0]==0 && orientation_[1]==0 && orientation_[2]==0)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - currently, wrapped items cannot be rotated, i.e. the orientation vector must be (0,0,0)" << endl;
    return false;
  }
  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItem::build(ofstream &file,
		      const string parcelName) const{

  file << endl;
  
  file << "############################################" << endl
       << "### item's main body" << endl << endl;
  
  file << "[" << name_ << "]" << endl;
  file << "type = box" << endl;
  file << "material = " << material_ << endl;
  file << "mother_volume = " << parcelName << "_log" << endl;
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

  if(!buildWrap(file, parcelName)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot wrap item named " << name_ << endl;
    return false;
  }
  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItem::buildWrap(ofstream &file,
			  const string parcelName) const{

  if(wrapMaterial_.size() != 0){
    if(orientation_[0] != 0. || orientation_[1] != 0. || orientation_[2] != 0.){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - currently, only items with (0,0,0) orientation can be wrapped" << endl;
      return false;
    }
  }
  
  vector<double> effectiveItemSize = size_;
  
  for(unsigned int i=0; i<wrapMaterial_.size(); i++){
    file << endl
	 << "############################################" << endl
	 << "### item's wrap layer " << i+1 << endl;

    // z+
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Top]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << effectiveItemSize[0]+2*wrapThickness_[i] << "mm "
	 << effectiveItemSize[1]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] << "mm "
      	 << position_[2] + 0.5 * effectiveItemSize[2] + 0.5 * wrapThickness_[i] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;

    // z-
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Bottom]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << effectiveItemSize[0]+2*wrapThickness_[i] << "mm "
	 << effectiveItemSize[1]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] << "mm "
      	 << position_[2] - 0.5 * effectiveItemSize[2] - 0.5 * wrapThickness_[i] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    // y+
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Left]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << effectiveItemSize[0]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm "
	 << effectiveItemSize[2] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] + 0.5 * effectiveItemSize[1] + 0.5 * wrapThickness_[i] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    // y-
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Right]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << effectiveItemSize[0]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm "
	 << effectiveItemSize[2] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] - 0.5 * effectiveItemSize[1] - 0.5 * wrapThickness_[i] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
        
    // x+
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Front]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << wrapThickness_[i] << "mm "
	 << effectiveItemSize[1] << "mm "
	 << effectiveItemSize[2] << "mm"
	 << endl;
    file << "position = "
      	 << position_[0] + 0.5 * effectiveItemSize[0] + 0.5 * wrapThickness_[i] << "mm "
	 << position_[1] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    // x-
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Back]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << wrapThickness_[i] << "mm "
	 << effectiveItemSize[1] << "mm "
	 << effectiveItemSize[2] << "mm"
	 << endl;
    file << "position = "
      	 << position_[0] - 0.5 * effectiveItemSize[0]- 0.5 * wrapThickness_[i] << "mm "
	 << position_[1] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    for(unsigned int j=0; j<effectiveItemSize.size(); j++) effectiveItemSize[j] += 2*wrapThickness_[i];
  }  
  
  return true;
}
