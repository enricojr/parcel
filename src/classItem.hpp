#ifndef CLASSITEM_HPP
#define CLASSITEM_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

class classItem{

public:

  classItem(classRandom *random,
	    classVolumeLogger *volumeLogger);
  
  ~classItem();

  void init();
  
  void print() const;

  bool assignParameter(const string parameter,
		       const string value,
		       const vector<double> origin,
		       const vector<double> motherSize);

  void shiftPosition(const vector<double> origin);
  
  bool check() const;

  bool build(ofstream &file,
	     const string parcelName) const;

private:

  classRandom *random_;
  classVolumeLogger *volumeLogger_;
  
  string name_;
  string type_;
  vector<double> size_;
  vector<double> position_;
  vector<double> orientation_;
  string material_;
  vector<string> wrapMaterial_;
  vector<double> wrapThickness_;

  bool checkSize(const vector<double> motherSize,
		 const vector<double> mean,
		 const vector<double> sigma) const;

  bool generatePositionUniform(const vector<double> motherSize);

  void generateOrientationUniform();
  
  void generateSizeGaussian(const vector<double> mean,
			    const vector<double> sigma);

  bool doesNotFit(const vector<double> motherSize) const;

  bool isANumber(const char character) const;

  double computeRadius() const;

  bool buildWrap(ofstream &file,
		 const string parcelName) const;

};

#endif
