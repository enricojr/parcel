#ifndef CLASSRANDOM_HPP
#define CLASSRANDOM_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

#include "defaults.hpp"

class classRandom{

public:

  classRandom();
  ~classRandom();

  void init();

  double generateRandomUniform(const double rangeMin,
			       const double rangeMax);
  
  double generateRandomGauss(const double mu,
			     const double sigma);
  
private:

  vector<pair<double, double> > gfGauss_; // generating function for the Gaussian distribution

  void initGeneratingFunctions();
  void initGFGauss();
  double getGaussian(const double randomNumber) const;
};

#endif
