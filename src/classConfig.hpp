#ifndef CLASSCONFIG_HPP
#define CLASSCONFIG_HPP

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "classRandom.hpp"
#include "classVolumeLogger.hpp"
#include "classParcel.hpp"
#include "classItem.hpp"
#include "classItemSet.hpp"

class classConfig{

public:
  
  classConfig(const string fileNameIn,
	      const string fileNameOut);
  ~classConfig();

  void init(const string fileNameIn,
	    const string fileNameOut);

  void print() const;

  int load();

  bool check() const;
  
  int build(const bool fullSetup);

private:

  // debug
  bool debug_;
  
  // I/O
  string fileNameIn_;
  string fileNameOut_;

  // random generator
  classRandom *random_;

  // volume logger
  classVolumeLogger *volumeLogger_;
  
  // parcel
  classParcel *parcel_;

  // items
  vector<classItem *> item_;

  // item sets
  vector<classItemSet *> itemSet_;

  // methods
  bool findNextSection(ifstream &file);
  int loadSection(ifstream &file);
  bool identifySection(const string line,
		       string  &name);
  bool loadParcel(ifstream &file);
  bool loadItem(ifstream &file);
  bool loadItemSet(ifstream &file);
  void buildSetup(ofstream &file);
};

#endif
