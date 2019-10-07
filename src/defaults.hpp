#ifndef DEFAULTS_HPP
#define DEFAULTS_HPP

namespace defaultValue{

  // random
  const double gfGaussRange = 5;
  const unsigned int gfGaussPrecision = 100;
  
  // parcel
  const string parcelName = "parcel";
  const string parcelType = "box";
  const vector<double> parcelSize(3, 0.);
  const vector<double> parcelPosition(3, 0.);
  const vector<double> parcelOrientation(3, 0.);
  const string parcelMaterial = "vacuum";

  // item
  const string itemName = "item";
  const string itemType = "box";
  const vector<double> itemSize(3, 0.);
  const vector<double> itemPosition(3, 0.);
  const vector<double> itemOrientation(3, 0.);
  const string itemMaterial = "vacuum";
  const unsigned int itemMaxAttemptsSize = 100;
  const unsigned int itemMaxAttemptsPosition = 100;
  
  // itemSet
  const string itemSetName = "itemSet";
  const string itemSetType = "box";
  const vector<double> itemSetSize(3, 0.);
  const vector<double> itemSetPosition(3, 0.);
  const vector<double> itemSetOrientation(3, 0.);
  const string itemSetMaterial = "vacuum";
  const unsigned int itemSetQuantity = 0;
  const unsigned int itemSetMaxAttemptsSize = 100;
  const unsigned int itemSetMaxAttemptsPosition = 100;
  const string itemSetItemType = "box";
  const string itemSetItemSize = "0 0 0";
  const string itemSetItemPosition = "0 0 0";
  const string itemSetItemOrientation = "0 0 0";
  const string itemSetItemWrapMaterial = "";
  const string itemSetItemWrapThickness = "";
  
}

#endif
