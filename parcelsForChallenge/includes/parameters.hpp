#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

namespace parameters{

  const string CONFIGPATH = "/home/dynaxion-rt/software/parcel/parcelsForChallenge/configs/";
  const string ALLPIX2PATH = "/home/dynaxion-rt/software/allpix-squared/bin/";
  const string RUNPATH = "/home/dynaxion-rt/software/parcel/parcelsForChallenge/";
  const string RAWDATAPUREPATH = "/home/dynaxion-rt/simulation/output/loop-challenge/pure/";
  const string FILENAMECALIBRATOR = "/home/dynaxion-rt/simulation/output/loop-challenge/pure/material_g4_calibrator.root";
  const string SPECTRAFILENAME = "/home/dynaxion-rt/simulation/output/loop-challenge-spectra/pureSpectra.root";
  const double PARCELSIZEX = 20.0;
  const double PARCELSIZEY = 10.0;
  const double PARCELSIZEZ = 4.2;
  const double PARCELTOSOURCEDISTANCE = 5.0;
  const unsigned int PRIORITYLEVEL = 10; // 0 = highest priority, 1 = adding more drugs, 2 = completing the explosives, 5 = completing the fentanyl family, 4 = adding some random mixes, 3 = adding some drugs, 6 = adding some random mixes, 7 = adding some harmless material, 8 = adding all drugs, 9 = adding all harmless materials, 10 = all
  const double TIMINGCUT = 100.; // timing cut (in ns) to ddistinguish between neutron capture and inelastic scattering
  const double ENERGYMIN = 0.;
  const double ENERGYMAX = 12.;
  const unsigned int ENERGYBINDENSITY = 100; // number of bins per MeV
  const unsigned int ENERGYNBINS = ENERGYBINDENSITY * (ENERGYMAX - ENERGYMIN);
  
  /***************//***************//***************//***************/
  /***************//***************//***************//***************/
  
  void getMaterials(vector<string> &material,
		    vector<double> &density,
		    vector<string> &type){
    
    //------// DRUGS
    if(PRIORITYLEVEL >= 0){ density.push_back(1.099);  material.push_back("g4_benzyl_butyryl_fentanyl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.1);  material.push_back("g4_benzyl_fentanyl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1);  material.push_back("g4_phenacetin");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.4);  material.push_back("g4_heroin");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.2);  material.push_back("g4_carfentanil");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.2);  material.push_back("g4_cocaine");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.2);  material.push_back("g4_ketamine");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_u47700");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_norfentanyl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_pethidine");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.1);  material.push_back("g4_ghb");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.1);  material.push_back("g4_mdma");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.4);  material.push_back("g4_oxycodone");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_furanyl_fentanyl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_cyclopropyl_fentanyl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_methoxyacetyl_fentanyl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_anpp");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_npp");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.099);  material.push_back("g4_benzyl_butyryl_fentanyl_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_benzyl_fentanyl_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.4);  material.push_back("g4_heroin_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.2);  material.push_back("g4_carfentanil_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.2);  material.push_back("g4_cocaine_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.2);  material.push_back("g4_ketamine_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_u47700_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.1);  material.push_back("g4_ghb_na");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.1);  material.push_back("g4_mdma_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.4);  material.push_back("g4_oxycodone_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_furanyl_fentanyl_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_cyclopropyl_fentanyl_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 5){ density.push_back(1.1);  material.push_back("g4_methoxyacetyl_fentanyl_hcl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(1.2);  material.push_back("g4_lsd");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1);  material.push_back("g4_cbd");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_gbl");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 1){ density.push_back(0.9);  material.push_back("g4_methamphetamine");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.3);  material.push_back("g4_dihydrocodeine");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1);  material.push_back("g4_tapentadol");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1);  material.push_back("g4_tramadol");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1);  material.push_back("g4_cocodamol");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_metandienone");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.2);  material.push_back("g4_oxymetholone");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.1);  material.push_back("g4_stanazolol");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_testosterone");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_trenbolone");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.4);  material.push_back("g4_alprazolam");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.1);  material.push_back("g4_ambien");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.3);  material.push_back("g4_armodafinil");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_carisoprodol");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.5);  material.push_back("g4_clonazepam");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_escitalopram");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.2);  material.push_back("g4_escoparone");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.8);  material.push_back("g4_tizanidine");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.3);  material.push_back("g4_valium");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1);  material.push_back("g4_viagra");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.4);  material.push_back("g4_xanax");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 8){ density.push_back(1.3);  material.push_back("g4_clenbuterol");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.1);  material.push_back("g4_mescaline");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.4);  material.push_back("g4_hydromorphone");  type.push_back("drug");}
    if(PRIORITYLEVEL >= 3){ density.push_back(1.3);  material.push_back("g4_hydrocodone");  type.push_back("drug");}

    //------// EXPLOSIVES
    if(PRIORITYLEVEL >= 0){ density.push_back(1.9);  material.push_back("g4_rdx");  type.push_back("explosive");}
    if(PRIORITYLEVEL >= 2){ density.push_back(1.7);  material.push_back("g4_petn");  type.push_back("explosive");}
    if(PRIORITYLEVEL >= 2){ density.push_back(1.6);  material.push_back("g4_tnt");  type.push_back("explosive");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1);  material.push_back("g4_tatp");  type.push_back("explosive");}
    if(PRIORITYLEVEL >= 2){ density.push_back(1.7);  material.push_back("g4_nitroglycerin");  type.push_back("explosive");}

    //------// HARMLESS
    if(PRIORITYLEVEL >= 0){ density.push_back(1.3);  material.push_back("g4_acetaminophen");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(2.2);  material.push_back("g4_ptfe");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.8);  material.push_back("g4_sucrose_sugar");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.7);  material.push_back("g4_cellulose_cotton");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.38);  material.push_back("g4_polyester");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.2);  material.push_back("g4_office_paper");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(0.689);  material.push_back("g4_cardboard");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(0.449);  material.push_back("g4_milk_powder");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.442);  material.push_back("g4_sand");  type.push_back("other");}
    if(PRIORITYLEVEL >= 9){ density.push_back(0.87);  material.push_back("g4_petrol");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(0.62);  material.push_back("g4_wood");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.33);  material.push_back("g4_toothpaste");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(0.9);  material.push_back("g4_soap");  type.push_back("other");}
    if(PRIORITYLEVEL >= 9){ density.push_back(1.3);  material.push_back("g4_aspirin");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1);  material.push_back("g4_ibuprofen");  type.push_back("other");}
    if(PRIORITYLEVEL >= 9){ density.push_back(1);  material.push_back("g4_heamoglobin");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.38);  material.push_back("g4_pet");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.49);  material.push_back("g4_viscose");  type.push_back("other");}
    if(PRIORITYLEVEL >= 9){ density.push_back(1);  material.push_back("g4_nicotine");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(0.0076);  material.push_back("g4_pstuffing");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.85);  material.push_back("g4_circuit_board");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(0.05);  material.push_back("g4_polystyrene_foam");  type.push_back("other");}
    if(PRIORITYLEVEL >= 0){ density.push_back(1.3);  material.push_back("g4_collagen");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(1.34);  material.push_back("g4_silk");  type.push_back("other");}
    if(PRIORITYLEVEL >= 9){ density.push_back(2.66);  material.push_back("g4_epsomsalts");  type.push_back("other");}
    if(PRIORITYLEVEL >= 7){ density.push_back(2.2);  material.push_back("g4_bakingsoda");  type.push_back("other");}
    if(PRIORITYLEVEL >= 9){ density.push_back(1.8);  material.push_back("g4_lactose");  type.push_back("other");}

    //------// MIXES
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf05l95");  type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf10l90");  type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf15l85"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf20l80"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf25l75"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf30l70"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf35l65"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf40l60"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf45l55"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf50l50"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf05bs95"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf10bs90"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf15bs85"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf20bs80"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf25bs75"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf30bs70"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf35bs65"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf40l60"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf45l55"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf50l50"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf05bs95"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf10bs90"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf15bs85"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf20bs80"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf25bs75"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf30bs70"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf35bs65"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf40bs60"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf45bs55"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf50bs50"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf05a95"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf10a90"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf15a85"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf20a80"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf25a75"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf30a70"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bbf35a65"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf40a60"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bbf45a55"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bbf50a50"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf05l95"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf10l90"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf15l85"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf20l80"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf25l75"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf30l70"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf35l65"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf40l60"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf45l55"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf50l50"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf05bs95"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf10bs90"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf15bs85"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf20bs80"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf25bs75"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf30bs70"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf35bs65"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf40bs60"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf45bs55"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf50bs50"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf05a95"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf10a90"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf15a85"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf20a80"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf25a75"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf30a70"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf35a65"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 4){ density.push_back(1.5);  material.push_back("g4_bf40a60"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 6){ density.push_back(1.5);  material.push_back("g4_bf45a55"); type.push_back("mix");}
    if(PRIORITYLEVEL >= 10){ density.push_back(1.5);  material.push_back("g4_bf50a50"); type.push_back("mix");}
    
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
