# parcel
Simplifies the generation of Allpix2 complex geometry files

For instructions on how to format the input configuration files, and how to run it, please refer to manual.pdf in doc/

In scripts/ you'll find the convert.C macro, which just takes the material lists from Emma as an input and produces the syntax codes for including the materials into allpix-squared or in other macros

# parcelsForChallenge
This folder contains the scripts one can use to automatically generate the parcel configuration files for the opioid challenge. Just run the following commands:
$ root -b -q generate.C
$ ./conver
All the configuration files will be stored in the configs/ subfolder