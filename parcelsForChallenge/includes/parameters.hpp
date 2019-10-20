#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

namespace parameters{

  const string CONFIGPATH = "/home/dynaxion-rt/software/parcel/parcelsForChallenge/configs/";
  const string ALLPIX2PATH = "/home/dynaxion-rt/software/allpix-squared/bin/";
  const string RUNPATH = "/home/dynaxion-rt/software/parcel/parcelsForChallenge/";
  const string RAWDATAPUREPATH = "/home/dynaxion-rt/simulation/output/loop-challenge/pure/";
  const string SPECTRAFILENAME = "/home/dynaxion-rt/simulation/output/loop-challenge-spectra/pureSpectra.root";
  const double PARCELSIZEX = 20.0;
  const double PARCELSIZEY = 10.0;
  const double PARCELSIZEZ = 4.2;
  const double PARCELTOSOURCEDISTANCE = 5.0;
  const unsigned int PRIORITYLEVEL = 2; // 0 = highest priority, 1 = adding more drugs, 2 = completing the explosives, 5 = completing the fentanyl family, 4 = adding some random mixes, 3 = adding some drugs, 6 = adding some random mixes, 7 = adding some harmless material, 8 = adding all drugs, 9 = adding all harmless materials, 10 = all
  const double TIMINGCUT = 100.; // timing cut (in ns) to ddistinguish between neutron capture and inelastic scattering
  const double ENERGYMIN = 0.;
  const double ENERGYMAX = 12.;
  const unsigned int ENERGYBINDENSITY = 100; // number of bins per MeV
  const unsigned int ENERGYNBINS = ENERGYBINDENSITY * (ENERGYMAX - ENERGYMIN);
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/
  
  void getMaterials(vector<string> &material,
		    vector<double> &density){
    
    //------// DRUGS
    if(PRIORITYLEVEL >= 0){ density.push_back(1.099);  material.push_back("g4_benzyl_butyryl_fentanyl");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.1);  material.push_back("g4_benzyl_fentanyl");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1);  material.push_back("g4_phenacetin");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.4);  material.push_back("g4_heroin");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.2);  material.push_back("g4_carfentanil");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.2);  material.push_back("g4_cocaine");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.2);  material.push_back("g4_ketamine");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_u47700");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_norfentanyl");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_pethidine");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.1);  material.push_back("g4_ghb");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.1);  material.push_back("g4_mdma");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.4);  material.push_back("g4_oxycodone");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_furanyl_fentanyl");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_cyclopropyl_fentanyl");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_methoxyacetyl_fentanyl");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_anpp");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_npp");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.099);  material.push_back("g4_benzyl_butyryl_fentanyl_hcl");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_benzyl_fentanyl_hcl");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.4);  material.push_back("g4_heroin_hcl");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.2);  material.push_back("g4_carfentanil_hcl");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.2);  material.push_back("g4_cocaine_hcl");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.2);  material.push_back("g4_ketamine_hcl");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_u47700_hcl");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.1);  material.push_back("g4_ghb_na");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.1);  material.push_back("g4_mdma_hcl");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.4);  material.push_back("g4_oxycodone_hcl");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_furanyl_fentanyl_hcl");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_cyclopropyl_fentanyl_hcl");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_methoxyacetyl_fentanyl_hcl");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.2);  material.push_back("g4_lsd");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1);  material.push_back("g4_cbd");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_gbl");}
    if(PRIORITYLEVEL >= 1){ density.push_back(0.9);  material.push_back("g4_methamphetamine");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.3);  material.push_back("g4_dihydrocodeine");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1);  material.push_back("g4_tapentadol");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1);  material.push_back("g4_tramadol");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1);  material.push_back("g4_cocodamol");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_metandienone");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.2);  material.push_back("g4_oxymetholone");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.1);  material.push_back("g4_stanazolol");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_testosterone");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_trenbolone");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.4);  material.push_back("g4_alprazolam");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.1);  material.push_back("g4_ambien");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.3);  material.push_back("g4_armodafinil");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_carisoprodol");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.5);  material.push_back("g4_clonazepam");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_escitalopram");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_escoparone");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.8);  material.push_back("g4_tizanidine");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.3);  material.push_back("g4_valium");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1);  material.push_back("g4_viagra");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.4);  material.push_back("g4_xanax");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.3);  material.push_back("g4_clenbuterol");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_mescaline");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.4);  material.push_back("g4_hydromorphone");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.3);  material.push_back("g4_hydrocodone");}

    //------// EXPLOSIVES
    if(PRIORITYLEVEL >= 0){ density.push_back(1.9);  material.push_back("g4_rdx");}
    if(PRIORITYLEVEL >= 2){ density.push_back(1.7);  material.push_back("g4_petn");}
    if(PRIORITYLEVEL >= 2){ density.push_back(1.6);  material.push_back("g4_tnt");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1);  material.push_back("g4_tatp");}
    if(PRIORITYLEVEL >= 2){ density.push_back(1.7);  material.push_back("g4_nitroglycerin");}

    //------// HARMLESS
    if(PRIORITYLEVEL >= 0){ density.push_back(1.3);  material.push_back("g4_acetaminophen");}
    if(PRIORITYLEVEL >= 7){ density.push_back(2.2);  material.push_back("g4_ptfe");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.8);  material.push_back("g4_sucrose_sugar");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.7);  material.push_back("g4_cellulose_cotton");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.38);  material.push_back("g4_polyester");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.2);  material.push_back("g4_office_paper");}
    if(PRIORITYLEVEL >= 0){ density.push_back(0.689);  material.push_back("g4_cardboard");}
    if(PRIORITYLEVEL >= 0){ density.push_back(0.449);  material.push_back("g4_milk_powder");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.442);  material.push_back("g4_sand");}
    if(PRIORITYLEVEL >= 9){ density.push_back(0.87);  material.push_back("g4_petrol");}
    if(PRIORITYLEVEL >= 7){ density.push_back(0.62);  material.push_back("g4_wood");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.33);  material.push_back("g4_toothpaste");}
    if(PRIORITYLEVEL >= 0){ density.push_back(0.9);  material.push_back("g4_soap");}
    if(PRIORITYLEVEL >= 9){ density.push_back(1.3);  material.push_back("g4_aspirin");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1);  material.push_back("g4_ibuprofen");}
    if(PRIORITYLEVEL >= 9){ density.push_back(1);  material.push_back("g4_heamoglobin");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.38);  material.push_back("g4_pet");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.49);  material.push_back("g4_viscose");}
    if(PRIORITYLEVEL >= 9){ density.push_back(1);  material.push_back("g4_nicotine");}
    if(PRIORITYLEVEL >= 7){ density.push_back(0.0076);  material.push_back("g4_pstuffing");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.85);  material.push_back("g4_circuit_board");}
    if(PRIORITYLEVEL >= 7){ density.push_back(0.05);  material.push_back("g4_polystyrene_foam");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.3);  material.push_back("g4_collagen");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.34);  material.push_back("g4_silk");}
    if(PRIORITYLEVEL >= 9){ density.push_back(2.66);  material.push_back("g4_epsomsalts");}
    if(PRIORITYLEVEL >= 7){ density.push_back(2.2);  material.push_back("g4_bakingsoda");}
    if(PRIORITYLEVEL >= 9){ density.push_back(1.8);  material.push_back("g4_lactose");}

    //------// MIXES
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf05l95");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf10l90");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf15l85");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf20l80");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf25l75");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf30l70");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf35l65");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf40l60");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf45l55");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf50l50");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf05bs95");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf10bs90");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf15bs85");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf20bs80");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf25bs75");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf30bs70");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf35bs65");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf40l60");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf45l55");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf50l50");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf05bs95");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf10bs90");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf15bs85");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf20bs80");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf25bs75");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf30bs70");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf35bs65");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf40bs60");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf45bs55");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf50bs50");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf05a95");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf10a90");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf15a85");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf20a80");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf25a75");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf30a70");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf35a65");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf40a60");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf45a55");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf50a50");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf05l95");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf10l90");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf15l85");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf20l80");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf25l75");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf30l70");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf35l65");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf40l60");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf45l55");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf50l50");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf05bs95");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf10bs90");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf15bs85");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf20bs80");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf25bs75");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf30bs70");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf35bs65");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf40bs60");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf45bs55");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf50bs50");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf05a95");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf10a90");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf15a85");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf20a80");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf25a75");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf30a70");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf35a65");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf40a60");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf45a55");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf50a50");}
    
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
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/

  string getHistNameCapture(const string material,
			    const string quantity){
    return "material_" + material + "_" + quantity + "g_capture";
  }
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/

  string getHistTitleCapture(const string material,
			     const string quantity){
    return material + ", " + quantity + "g, capture";
  }
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/

  string getHistNameInelastic(const string material,
			      const string quantity){
    return "material_" + material + "_" + quantity + "g_inelastic";
  }
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/

  string getHistTitleInelastic(const string material,
			       const string quantity){
    return material + ", " + quantity + "g, inelastic";
  }
  
}

#endif
