#ifndef CLASSVOLUMELOGGER_HPP
#define CLASSVOLUMELOGGER_HPP

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

class classBubble{

public:

  classBubble(const vector<double> pos,
	      const double rad,
	      const bool fromItemSet = false) : position(pos), radius(rad), isItemSet(fromItemSet) {
  };
  
  ~classBubble(){
    position.clear();
  };

  void print() const{
    cout << __PRETTY_FUNCTION__ << ": position = (";
    for(unsigned int i=0; i<3; i++){
      cout << position[i];
      if(i<2) cout << ",";
    }
    cout << ")" << endl;
    cout << __PRETTY_FUNCTION__ << ": radius = " << radius << endl; 
  };

  bool overlap(const vector<double> otherPosition,
	       const double otherRadius){
    const double dx = otherPosition[0] - position[0];
    const double dy = otherPosition[1] - position[1];
    const double dz = otherPosition[2] - position[2];
    const double distance = sqrt(dx*dx + dy*dy + dz*dz);
    if(distance <= radius + otherRadius) return true;
    else return false;
  };

  bool isItemSet;
  vector<double> position;
  double radius;
  
private:
};

/********************//********************//********************//********************//********************/
/********************//********************//********************//********************//********************/

class classVolumeLogger{

public:

  classVolumeLogger();
  ~classVolumeLogger();

  void init();

  void print() const;

  void addBubble(const vector<double> position,
		 const double radius,
		 const bool isItemSet = false);

  bool spaceIsFree(const vector<double> position,
		   const double radius,
		   const bool excludeItemSets = true) const;
  
private:

  vector<classBubble *> bubble_;
  
};

#endif
