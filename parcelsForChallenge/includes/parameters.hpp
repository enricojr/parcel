#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

namespace parameters{

  const string CONFIGPATH = "/home/dynaxion-rt/software/parcel/parcelsForChallenge/configs/";
  const string ALLPIX2PATH = "/home/dynaxion-rt/software/allpix-squared/bin/";
  const string RUNPATH = "/home/dynaxion-rt/software/parcel/parcelsForChallenge/";
  const string RAWDATAPUREPATH = "/home/dynaxion-rt/simulation/output/loop-challenge/pure/";
  const double PARCELSIZEX = 20.0;
  const double PARCELSIZEY = 10.0;
  const double PARCELSIZEZ = 4.2;
  const double PARCELTOSOURCEDISTANCE = 5.0;
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/
  
  void getMaterials(vector<string> &material,
		    vector<double> &density){
    density.push_back(1.099); material.push_back("g4_benzyl_butyryl_fentanyl");
    density.push_back(1.100); material.push_back("g4_benzyl_fentanyl");
    density.push_back(1.200); material.push_back("g4_carfentanil");
    density.push_back(1.099); material.push_back("g4_benzyl_butyryl_fentanyl_hcl");
    density.push_back(1.100); material.push_back("g4_benzyl_fentanyl_hcl");
    density.push_back(1.900); material.push_back("g4_rdx");
    density.push_back(1.000); material.push_back("g4_tatp");
    density.push_back(1.800); material.push_back("g4_sucrose_sugar");
    density.push_back(1.700); material.push_back("g4_cellulose_cotton");
    density.push_back(1.380); material.push_back("g4_polyester");
    density.push_back(1.200); material.push_back("g4_office_paper");
    density.push_back(0.449); material.push_back("g4_milk_powder");
    density.push_back(1.330); material.push_back("g4_toothpaste");
    density.push_back(0.900); material.push_back("g4_soap");
    density.push_back(0.689); material.push_back("g4_cardboard");
    density.push_back(1.300); material.push_back("g4_acetaminophen");
    density.push_back(1.300); material.push_back("g4_collagen");    
    return ;
  }
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/

  void getQuantity(vector<double> &quantity){
    quantity.push_back(1000);
    quantity.push_back(500);
    quantity.push_back(200);
    quantity.push_back(100);
    quantity.push_back(50);
    return ;
  }
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/

  string getFileNamePureSimulation(const string material,
				   const string quantity){
    return CONFIGPATH + "simulation_" + material + "_" + quantity + "g.conf";
  }
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/

  string getFileNamePureMaterial(const string material,
				 const string quantity){
    return CONFIGPATH + "material_" + material + "_" + quantity + "g.conf";
  }
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/

  string getFileNamePureRawData(const string material,
				const string quantity){
    return RAWDATAPUREPATH + "material_" + material + "_" + quantity + "g.root";
  }
  
}

#endif
