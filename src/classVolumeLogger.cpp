#include "classVolumeLogger.hpp"

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classVolumeLogger::classVolumeLogger(){
  init();
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

classVolumeLogger::~classVolumeLogger(){
  for(unsigned int i=0; i<bubble_.size(); i++){
    delete bubble_[i];
  }
  bubble_.clear();
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classVolumeLogger::init(){
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classVolumeLogger::print() const{

  for(unsigned int i=0; i<bubble_.size(); i++){
    cout << __PRETTY_FUNCTION__ << ": bubble #" << i+1 << endl;
    bubble_[i] -> print();
  }
  
  return ;
}

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

void classVolumeLogger::addBubble(const vector<double> position,
				  const double radius,
				  const bool isItemSet){
  bubble_.push_back(new classBubble(position, radius, isItemSet));
  return ;
}
  
/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

bool classVolumeLogger::spaceIsFree(const vector<double> position,
				    const double radius,
				    const bool excludeItemSets) const{
  for(unsigned int i=0; i<bubble_.size(); i++){
    if(excludeItemSets && bubble_[i] -> isItemSet) continue;
    if(bubble_[i] -> overlap(position, radius)) return false;
    else continue;
  }
  return true;
}
