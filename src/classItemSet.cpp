#include "classItemSet.hpp"
#include "defaults.hpp"

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classItemSet::classItemSet(classRandom *random,
			   classVolumeLogger *volumeLogger){
  random_ = random;
  volumeLogger_ = volumeLogger;
  init();
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classItemSet::~classItemSet(){
  size_.clear();
  position_.clear();
  orientation_.clear();
  for(unsigned int i=0; i<item_.size(); i++){
    delete item_[i];
  }
  item_.clear();
  wrapMaterial_.clear();
  wrapThickness_.clear();
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classItemSet::init(){

  name_ = defaultValue::itemSetName;
  type_ = defaultValue::itemSetType;
  size_ = defaultValue::itemSetSize;
  position_ = defaultValue::itemSetPosition;
  orientation_ = defaultValue::itemSetOrientation;
  material_ = defaultValue::itemSetMaterial;
  quantity_ = defaultValue::itemSetQuantity;
  itemType_ = defaultValue::itemSetItemType;
  itemSize_ = defaultValue::itemSetItemSize;
  itemPosition_ = defaultValue::itemSetItemPosition;
  itemOrientation_ = defaultValue::itemSetItemOrientation;
  fillParcel_ = false;
  
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classItemSet::print() const{

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

  cout << __PRETTY_FUNCTION__ << ": quantity = " << quantity_ << endl;

  cout << __PRETTY_FUNCTION__ << ": itemType = " << itemType_ << endl;
  cout << __PRETTY_FUNCTION__ << ": itemSize = " << itemSize_ << endl;
  cout << __PRETTY_FUNCTION__ << ": itemPosition = " << itemPosition_ << endl;
  cout << __PRETTY_FUNCTION__ << ": itemOrientation = " << itemOrientation_ << endl;

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

  for(unsigned int i=0; i<item_.size(); i++){
    cout << __PRETTY_FUNCTION__ << ": item #" << i+1 << endl;
    item_[i] -> print();
  }
  
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItemSet::checkSize(const vector<double> motherSize,
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

bool classItemSet::generatePositionUniform(const vector<double> motherSize){

  for(unsigned int i=0; i<3; i++){
    const double min = -0.5 * motherSize[i] + 0.5 * size_[i];
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

void classItemSet::generateSizeGaussian(const vector<double> mean,
					const vector<double> sigma){

  for(unsigned int i=0; i<3; i++){
    size_[i] = random_ -> generateRandomGauss(mean[i], sigma[i]);
  }
  
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItemSet::doesNotFit(const vector<double> motherSize) const{

  for(unsigned int i=0; i<3; i++){
    if(size_[i] > motherSize[i]){
      return true;
    }
  }
  
  return false;
}
  
/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItemSet::isANumber(const char character) const{
  if(character == 43) return true; // +
  else if(character == 45) return true; // -
  else if(character == 46) return true; // .
  if(character >= 48 && character <= 57) return true; // 0-9
  else return false;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

double classItemSet::computeRadius() const{
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

void classItemSet::shiftPosition(const vector<double> origin){
  for(unsigned int i=0; i<3; i++){
    position_[i] += origin[i];
  }
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItemSet::assignParameter(const string parameter,
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
    if(first == "all"){
      size_ = motherSize;
      position_ = origin;
      fillParcel_ = true;
    }
    else if(first == "random"){
      if(second == "gauss"){
	vector<double> mean(3, 0.);
	vector<double> sigma(3, 0.);
	sscanf(value.c_str(), "random gauss %lf %lf %lf %lf %lf %lf", &mean[0], &mean[1], &mean[2], &sigma[0], &sigma[1], &sigma[2]);
	if(!checkSize(motherSize, mean, sigma)){
	  cout << __PRETTY_FUNCTION__ << ": WARNING!!! - one or more dimensions of this item set might be close to the mother volume dimensions. This may slow down the item set generation. Consider resizing this item set, or giving it a fixed size." << endl;
	  return false;
	}	
	unsigned int nAttempts = 1;
	generateSizeGaussian(mean, sigma);
	while(doesNotFit(motherSize)){
	  nAttempts ++;
	  generateSizeGaussian(mean, sigma);
	  if(nAttempts > defaultValue::itemSetMaxAttemptsSize){
	    cout << __PRETTY_FUNCTION__ << ": WARNING!!! - reached maximum number of attempts (" << defaultValue::itemSetMaxAttemptsSize << ") to generate random size. The item set named " << name_ << " will not be allocated." << endl;
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

    if(fillParcel_){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - even though the item set is filling the full parcel volume, a position is specified. This must be removed" << endl;
      return false;
    }
    
    const double radius = computeRadius();
    
    if(first == "center"){
      position_ = vector<double>(3, 0.);
      if(!volumeLogger_ -> spaceIsFree(position_, radius, false)){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - item set named " << name_ << " cannot be placed, overlapping with other items or item sets" << endl;
	return false;
      }
    }
    else if(first == "random"){      
      if(second == "uniform"){
	unsigned int nAttempts = 1;
	if(!generatePositionUniform(motherSize)){
	  cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot generate random position for item set named " << name_ << endl;
	  return false;
	}
	while(!volumeLogger_ -> spaceIsFree(position_, radius, false)){
	  nAttempts ++;
	  generatePositionUniform(motherSize);
	  if(nAttempts > defaultValue::itemSetMaxAttemptsPosition){
	    cout << __PRETTY_FUNCTION__ << ": WARNING!!! - reached maximum number of attempts (" << defaultValue::itemSetMaxAttemptsPosition << ") to generate random position. The item set named " << name_ << " will not be allocated." << endl;
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
      if(!volumeLogger_ -> spaceIsFree(position_, radius, false)){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - item set named " << name_ << " cannot be placed, overlapping with other items or item sets" << endl;
	return false;
      }
    }
    volumeLogger_ -> addBubble(position_, radius, true);
    volumeLogger_ -> print();
  }
  else if(parameter == "orientation"){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - user-set orientation not implemented (yet). This parameter must be removed" << endl;
    return false;
  }
  else if(parameter == "material"){
    material_ = value;
  }
  else if(parameter == "quantity"){
    sscanf(value.c_str(), "%d", &quantity_);
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
  else if(parameter == "itemType"){
    itemType_ = value;
  }
  else if(parameter == "itemSize"){
    itemSize_ = value;
  }
  else if(parameter == "itemPosition"){
    itemPosition_ = value;
  }
  else if(parameter == "itemOrientation"){
    itemOrientation_ = value;
  }
  else if(parameter == "itemWrapMaterial"){
    itemWrapMaterial_ = value;
  }
  else if(parameter == "itemWrapThickness"){
    itemWrapThickness_ = value;
  }
  else{
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - undefined parameter: " << parameter << endl;
    //    return false;
  }
  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItemSet::buildWrap(ofstream &file,
			     const string parcelName) const{

  if(wrapMaterial_.size() != 0){
    if(orientation_[0] != 0. || orientation_[1] != 0. || orientation_[2] != 0.){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - currently, only item sets with (0,0,0) orientation can be wrapped" << endl;
      return false;
    }
  }
  
  vector<double> effectiveItemSetSize = size_;
  
  for(unsigned int i=0; i<wrapMaterial_.size(); i++){
    file << endl
	 << "############################################" << endl
	 << "### item set's wrap layer " << i+1 << endl;

    // z+
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Top]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << effectiveItemSetSize[0]+2*wrapThickness_[i] << "mm "
	 << effectiveItemSetSize[1]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] << "mm "
      	 << position_[2] + 0.5 * effectiveItemSetSize[2] + 0.5 * wrapThickness_[i] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;

    // z-
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Bottom]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << effectiveItemSetSize[0]+2*wrapThickness_[i] << "mm "
	 << effectiveItemSetSize[1]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] << "mm "
      	 << position_[2] - 0.5 * effectiveItemSetSize[2] - 0.5 * wrapThickness_[i] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    // y+
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Left]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << effectiveItemSetSize[0]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm "
	 << effectiveItemSetSize[2] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] + 0.5 * effectiveItemSetSize[1] + 0.5 * wrapThickness_[i] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    // y-
    file << endl << "[" << name_ << "WrapLayer" << i+1 << "Right]" << endl;
    file << "type = box" << endl;
    file << "material = " << wrapMaterial_[i] << endl;
    file << "mother_volume = " << parcelName << "_log" << endl;
    file << "size = "
	 << effectiveItemSetSize[0]+2*wrapThickness_[i] << "mm "
	 << wrapThickness_[i] << "mm "
	 << effectiveItemSetSize[2] << "mm"
	 << endl;
    file << "position = "
	 << position_[0] << "mm "
      	 << position_[1] - 0.5 * effectiveItemSetSize[1] - 0.5 * wrapThickness_[i] << "mm "
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
	 << effectiveItemSetSize[1] << "mm "
	 << effectiveItemSetSize[2] << "mm"
	 << endl;
    file << "position = "
      	 << position_[0] + 0.5 * effectiveItemSetSize[0] + 0.5 * wrapThickness_[i] << "mm "
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
	 << effectiveItemSetSize[1] << "mm "
	 << effectiveItemSetSize[2] << "mm"
	 << endl;
    file << "position = "
      	 << position_[0] - 0.5 * effectiveItemSetSize[0]- 0.5 * wrapThickness_[i] << "mm "
	 << position_[1] << "mm "
      	 << position_[2] << "mm"
	 << endl;
    file << "orientation = 0deg 0deg 0deg" << endl;
    
    for(unsigned int j=0; j<effectiveItemSetSize.size(); j++) effectiveItemSetSize[j] += 2*wrapThickness_[i];
  }  
  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItemSet::build(ofstream &file,
			 const string parcelName){

  if(!buildWrap(file, parcelName)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot wrap item set named " << name_ << endl;
    return false;
  }

  for(unsigned int i=0; i<quantity_; i++){
    if(!generateItem(file, parcelName, i+1)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot generate item from set named " << name_ << endl;
      return false;
    }
  }

  for(unsigned int i=0; i<item_.size(); i++){
    if(!item_[i] -> build(file, parcelName)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot build item from set named " << name_ << endl;
      return false;
    }
  }
  
  return true;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classItemSet::generateItem(ofstream &file,
				const string parcelName,
				const unsigned int itemNumber){

  classItem *item = new classItem(random_, volumeLogger_);

  // name
  stringstream itemNumber_ss;
  itemNumber_ss << itemNumber;
  string itemName = name_ + "Item" + itemNumber_ss.str();  
  if(!item -> assignParameter("name", itemName, position_, size_)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << "name" << " = " << itemName << endl;
    return false;
  }

  // type
  if(!item -> assignParameter("type", "box", position_, size_)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << "type" << " = " << "box" << endl;
    return false;
  }

  // size
  if(!item -> assignParameter("size", itemSize_, position_, size_)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << "size" << " = " << itemSize_ << endl;
    return false;
  }
  
  // position
  if(!item -> assignParameter("position", itemPosition_, position_, size_)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << "position" << " = " << itemPosition_ << endl;
    return false;
  }
  item -> shiftPosition(position_);
  
  // orientation
  if(!item -> assignParameter("orientation", itemOrientation_, position_, size_)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << "orientation" << " = " << itemOrientation_ << endl;
    return false;
  }
  
  // material
  if(!item -> assignParameter("material", material_, position_, size_)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << "material" << " = " << material_ << endl;
    return false;
  }
  
  // wrap material
  if(itemWrapMaterial_ != defaultValue::itemSetItemWrapMaterial){
    if(!item -> assignParameter("wrapMaterial", itemWrapMaterial_, position_, size_)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << "itemWrapMaterial" << " = " << itemWrapMaterial_ << endl;
      return false;
    }
    if(!item -> assignParameter("wrapThickness", itemWrapThickness_, position_, size_)){
      cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot assign parameter " << "itemWrapThickness" << " = " << itemWrapThickness_ << endl;
      return false;
    }
  }
  
  item_.push_back(item);
  
  return true;
}
