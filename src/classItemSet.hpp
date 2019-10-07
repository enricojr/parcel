#ifndef CLASSITEMSET_HPP
#define CLASSITEMSET_HPP

#include <iostream>
#include <vector>
using namespace std;

#include "classRandom.hpp"
#include "classVolumeLogger.hpp"
#include "classItem.hpp"

class classItemSet{

public:

  classItemSet(classRandom *random,
	       classVolumeLogger *volumeLogger);
  
  ~classItemSet();

  void init();

  void print() const;

  bool assignParameter(const string parameter,
		       const string value,
		       const vector<double> origin,
		       const vector<double> motherSize);
  
  bool build(ofstream &file,
	     const string parcelName);

private:
  
  string name_;
  string type_;
  vector<double> size_;
  vector<double> position_;
  vector<double> orientation_;
  string material_;
  vector<string> wrapMaterial_;
  vector<double> wrapThickness_;
  unsigned int quantity_;
  string itemType_;
  string itemSize_;
  string itemPosition_;
  string itemOrientation_;
  string itemWrapMaterial_;
  string itemWrapThickness_;
  bool fillParcel_;

  classRandom *random_;
  classVolumeLogger *volumeLogger_;

  vector<classItem *> item_;
  
  bool checkSize(const vector<double> motherSize,
		 const vector<double> mean,
		 const vector<double> sigma) const;

  bool generatePositionUniform(const vector<double> motherSize);

  void generateSizeGaussian(const vector<double> mean,
			    const vector<double> sigma);

  bool doesNotFit(const vector<double> motherSize) const;

  bool isANumber(const char character) const;
  
  double computeRadius() const;

  void shiftPosition(const vector<double> origin);  

  bool buildWrap(ofstream &file,
		 const string parcelName) const;

  bool generateItem(ofstream &file,
		    const string parcelName,
		    const unsigned int itemNumber);

};

#endif
