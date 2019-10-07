#ifndef CLASSPARCEL_HPP
#define CLASSPARCEL_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class classParcel{

public:

  classParcel();
  ~classParcel();

  void init();
  
  void print() const;

  vector<double> getPosition() const;
  vector<double> getSize() const;
  string getName() const;
  
  bool assignParameter(const string parameter,
		       const string value);

  bool check() const;

  bool build(ofstream &file) const;

  bool buildWrap(ofstream &file) const;

private:

  string name_;
  string type_;
  vector<double> size_;
  vector<double> position_;
  vector<double> orientation_;
  string material_;
  vector<string> wrapMaterial_;
  vector<double> wrapThickness_;
  
};

#endif
