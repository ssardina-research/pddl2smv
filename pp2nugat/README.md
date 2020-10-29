# From PP-LPG format to NuGAT SMV

This script converts agent planning programs in the original PP-LPG format to SMV format for NuGAT solver.

## Example

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

## Changes (from TLV parser)

This translator is a variant of the one for TLV with a few changes to make it NuGAT compatible.


1. Remove `Main` module completely.
2. There are three `case` statements that are _not_ exhaustive. So we add an extra dummy case: `TRUE : TRUE`. This should not change the semantics as that case should never be used in reality.
3. Used `FALSE` for boolean instead of `0` (`0` does not work anymore from  SMV 2.5.4).
4. Finall, we generate the following at the end to define the game:

    ```bash
	GAME

	--- NON-DETERMINISTIC ENVIRONMENT PLAYER
	PLAYER_1
	VAR
	  dom : environment_module(agent);

	--- CONTROLLER PLAYER ENVIRONMENT
	PLAYER_2
	VAR
	  agent : system_module(dom);


	BUCHIGAME PLAYER_2 (agent.last)
    ```

## Original translator

The original translator for TLV was done by Fabio Patrizi (patrizi@dis.uniroma1.it) in 2015.

The adaptation for NuGAT was done by Sebastian Sardina in 2015.

Clean-up done in October 2020.