#include "includes/parameters.hpp"

/***************//***************//***************//***************/
/***************//***************//***************//***************/

int buildParcel(const string material,
		const double volume,
		const string fileNameSimulation,
		const string fileNameMaterial,
		TRandom3 *random){

  const double scaler = pow(volume / (parameters::PARCELSIZEX * parameters::PARCELSIZEY * parameters::PARCELSIZEZ), 1./3.);
  const double sizeX  = scaler * parameters::PARCELSIZEX;
  const double sizeY  = scaler * parameters::PARCELSIZEY;
  const double sizeZ  = scaler * parameters::PARCELSIZEZ;
  const double parcelToSourceDistance = parameters::PARCELTOSOURCEDISTANCE + sizeZ / 2.;
  
  const unsigned int randomSeed = (unsigned int) 100000000 * random -> Uniform();
  
  ofstream file;
  
  cout << __PRETTY_FUNCTION__ << ": creating file " << fileNameSimulation << endl;
  file.open(fileNameSimulation.c_str());
  if(!file){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot open file " << fileNameSimulation << endl;
    return 1;
  }
  
  file << "[Allpix]" << endl;
  file << "number_of_events = 1000000" << endl;
  file << "detectors_file = \"enrico_test_geometry.conf\"" << endl;
  file << "passive_materials_file = \"" << fileNameMaterial << "\"" << endl;
  file << "random_seed = " << randomSeed << endl;
  file << "model_paths = ./" << endl;
  file << "" << endl;
  file << "[GeometryBuilderGeant4]" << endl;
  file << "world_material = air" << endl;
  file << "" << endl;
  file << "[PassiveMaterialBuilderGeant4]" << endl;
  file << "" << endl;
  file << "[DepositionGeant4]" << endl;
  file << "physics_list = QGSP_BIC_HP" << endl;
  file << "particle_type = \"neutron\"" << endl;
  file << "source_energy = 6MeV" << endl;
  file << "source_position = 0um 0um 0mm" << endl;
  file << "beam_direction = 0 0 1" << endl;
  file << "source_type =  \"macro\"" << endl;
  file << "file_name = \"source_spectra.mac\"" << endl;
  file << "output = \"allparticles\"" << endl;
  file << "" << endl;
  file << "[ParticleDistributions]" << endl;
  file << "output_plots = 1" << endl;
  file << "store_particles = 1" << endl;
  file << "activate_detectors = 1" << endl;
  file << "input = \"allparticles\"" << endl;
  file << "output = \"selectedParticles\"" << endl;
  file << "detector_distance = -35cm" << endl;
  file << "detector_size = 76.2mm" << endl;
  file << "detector_thickness = 76.2mm" << endl;
  file << "detector_type = \"cebr3\"" << endl;
  file << "enable_display = 1" << endl;
  file << "write_to_database = 0" << endl;
  
  file.close();

  cout << __PRETTY_FUNCTION__ << ": creating file " << fileNameMaterial << endl;
  file.open(fileNameMaterial.c_str());
  if(!file){
    cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot open file " << fileNameMaterial << endl;
    return 1;
  }
  
  file << "[Lithium_target]" << endl;
  file << "type = box" << endl;
  file << "size = 50mm 50mm" << endl;
  file << "thickness = 2mm" << endl;
  file << "material = vacuum" << endl;
  file << "position = 0mm 0mm 0mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[accelerator]" << endl;
  file << "type = box" << endl;
  file << "size = 134mm 134mm" << endl;
  file << "thickness = 2000mm" << endl;
  file << "material = copper" << endl;
  file << "position = 0mm 0mm 1012mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[conveyer_belt]" << endl;
  file << "type = box" << endl;
  file << "size = 10000mm 700mm" << endl;
  file << "thickness = 6mm" << endl;
  file << "material = air" << endl;
  file << "position = 0mm 0mm -353mm" << endl;
  file << "orientation = 0 0 0" << endl;
  file << "" << endl;
  file << "[parcel]" << endl;
  file << "type = box" << endl;
  file << "material = " << material << endl;
  file << "size = " << sizeX << "cm " << sizeY << "cm" << endl;
  file << "thickness = " << sizeZ << "cm" << endl;
  file << "position = 0cm 0cm -" << parcelToSourceDistance << "cm" << endl;
  file << "orientation = 0deg 0deg 0deg" << endl;
  
  file.close();

  return 0;
}

/***************//***************//***************//***************/
/***************//***************//***************//***************/

int generatePure(){

  vector<string> material;
  vector<double> density;
  vector<string> type;
  parameters::getMaterials(material, density, type);

  vector<double> quantity;
  parameters::getQuantity(quantity);

  ofstream file("run.sh");
  file << "### expected running time for full set: " << 8. * material.size() * quantity.size() / 60 << "h" << endl;
  TRandom3 *random = new TRandom3();     
  for(unsigned int iMaterial=0; iMaterial<material.size(); iMaterial++){
    for(unsigned int iQuantity=0; iQuantity<quantity.size(); iQuantity++){
      cout << __PRETTY_FUNCTION__ << ": processing material " << material[iMaterial] << "\t " << quantity[iQuantity] << " g" << endl;
      const double volume = quantity[iQuantity] / density[iMaterial];
      stringstream quantity_ss;
      quantity_ss << quantity[iQuantity];
      const string quantity_s = quantity_ss.str();
      const string fileNameSimulation = parameters::getFileNamePureSimulation(material[iMaterial], quantity_s);
      const string fileNameMaterial = parameters::getFileNamePureMaterial(material[iMaterial], quantity_s);
      if(buildParcel(material[iMaterial], volume, fileNameSimulation, fileNameMaterial, random)){
	cout << __PRETTY_FUNCTION__ << ": ERROR!!! - cannot build material " << material[iMaterial] << "\t " << quantity[iQuantity] << " g" << endl;
	return 1;
      }
      file << parameters::ALLPIX2PATH << "allpix -c " << fileNameSimulation << endl;
      file << "mv " << parameters::RUNPATH << "output/modules.root " << parameters::getFileNamePureRawData(material[iMaterial], quantity_s) << endl;
    }
  }
  delete random;
  file.close();
  
  return 0;
}
