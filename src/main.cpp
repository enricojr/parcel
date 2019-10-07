#include <iostream>
#include <sstream>
using namespace std;

#include "classConfig.hpp"

int main(int argc, char *argv[]){

  if(argc != 4){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - too few arguments are provided" << endl;
    cout << __PRETTY_FUNCTION__ << ": please use the following syntax:" << endl;
    cout << __PRETTY_FUNCTION__ << ": " << argv[0] << " <fileNameIn> <fileNameOut> <fullSetup>" << endl;
    cout << __PRETTY_FUNCTION__ << ": set <fullSetup> to 1 if all the other setup elements must be added (target, accelerator, belt), 0 otherwise" << endl; 
    return 1;
  }

  stringstream fileNameIn_ss;
  fileNameIn_ss << argv[1];
  stringstream fileNameOut_ss;
  fileNameOut_ss << argv[2];
  const bool fullSetup = atoi(argv[3]);
  
  classConfig *config = new classConfig(fileNameIn_ss.str(), fileNameOut_ss.str());
  if(config -> load()){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot load input configuration" << endl;
    return 1;
  }
  if(!config -> check()){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - configuration consistency check not passed" << endl;
    return 1;
  }
  if(config -> build(fullSetup)){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot build input configuration" << endl;
    return 1;
  }
  config -> print();
  
  delete config;
  return 0;
}
