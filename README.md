####### parcel
Simplifies the generation of Allpix2 complex geometry files

For instructions on how to format the input configuration files, and how to run it, please refer to manual.pdf in doc/

In scripts/ you'll find the convert.C macro, which just takes the material lists from Emma as an input and produces the syntax codes for including the materials into allpix-squared or in other macros

####### parcelsForChallenge
This folder contains the scripts one can use to automatically generate the parcel configuration files for the opioid challenge. There are a few versions of them. All the configuration generated files will be stored in the configs/ subfolder

To generate the complex parcels, run the following commands:
$ root -b -q generate.C
$ ./convert

To generate parcels of pure materials of different amounts, run the following command:
$ root -b -q generatePure.C
The materials and amounts lists are defined in includes/parameters.hpp. The code also generates the shell script run.sh, with all the shell commands needed to run the simulation of all the generated setups. By default, each setup will be run for 1M events (or whatever number is hard-coded in generatePure.C). Each event is initialized with a randomly generated seed. To increase the statistics, re-generate all the configuration files, as new seeds need to be produced. CAREFUL!!! : this will overwrite the old configuration files. EVEN MORE CAREFUL!!! - running the run.sh script will overwrite the old raw data files.