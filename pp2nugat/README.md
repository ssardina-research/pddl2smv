# From PP-LPG format to NuGAT SMV

This script converts agent planning programs in the original PP-LPG format to SMV format for NuGAT solver.

It is an adapted version of the one Fabio Patrizi did for SMV for TLV.

Sebastian Sardina - ssardina@gmail.com - March 2015


## Install and run

First, you need to install Bison 2.4, which is provided under `tools/`, in folder `/opt/bison-2.4`:

Then run just run `make` to obtain `pp2nugat` binary, which can be used as follows:

```bash
cd examples

../pp2nugat < basic-v2.pddl > basic-v2.pddl

<nugatnugat-0.6.0.git./cmake-build-release/NuGaT -dynamic basic-v2.smv

*** This is NuGaT 0.6.0 (compiled on Wed Feb 21 15:22:21 2018)
*** Enabled addons are: game 
*** For more information on NuGaT see <http://es.fbk.eu/tools/nugat>
*** or email to <nugat-users@list.fbk.eu>.
*** Please report bugs to <Please report bugs to <nusmv-users@fbk.eu>>.
*** Copyright (c) 2010, Fondazione Bruno Kessler

*** This version of NuGAT-0.6.0 is linked to NuSMV 2.6.0.
*** For more information on NuSMV see <http://nusmv.fbk.eu>
*** or email to <nusmv-users@list.fbk.eu>.
*** Copyright (C) 2010-2014, Fondazione Bruno Kessler

*** This version of NuGAT-0.6.0 is linked to the CUDD library version 2.4.1
*** Copyright (c) 1995-2004, Regents of the University of Colorado

*** This version of NuGAT-0.6.0 is linked to the MiniSat SAT solver. 
*** See http://minisat.se/MiniSat.html
*** Copyright (c) 2003-2006, Niklas Een, Niklas Sorensson
*** Copyright (c) 2007-2010, Niklas Sorensson

*** WARNING: Game addon does not support properties COI size sorting.  ***
*** WARNING: Properties COI size sorting will be disabled.             ***
--   BuchiGame PLAYER_2 (agent.last)  : the strategy has been found
```

## Changes

The changes done are:

- added the bottom part for the GAME section.
- removed the Main module.
- completed a few case .. `easc` constructs with `TRUE : TRUE`; (all marked with "Seb" as comment in the code)
- used `FALSE` for boolean instead of `0` (it does not work anymore with `0` in the SMV 2.5.4)

## Original translator

Created: October 2010
Author: Fabio Patrizi
e-mail: f.patrizi@imperial.ac.uk, patrizi@dis.uniroma1.it

COMPILATION TIPS:

To generate the parser, you need Bison 2.4. 
However, if you do not plan to change the parser, you can use the one provided with this release.

As for the scanner, the program was compiled using Flex 2.5.35, though other versions might work as well

All tools necessary for compilation are included `tools/` (except of course, the c++ compiler ;-) )

`make all` should work. Good Luck.
