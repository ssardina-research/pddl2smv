# pddl2smv: LTL Planning via Model Checking

This program takes a file containing:

- a deterministic planning domain described in PDDL
- an LTL goal
(for an example of input format see `examples/basic4.pddl`)

and returns an SMV input description where:

- the system represents the possible evolution of the planning domain
- the LTL specification is the negation of the original LTL goal, translated on the SMV system (for an example of output format see `examples/basic4.smv`)

Upon execution (with the SMV file as input), the model checker (`NuSMV`) returns a counterexample for the LTL goal that represents a (infinite) plan satisfying the goal.

## Running it

Make sure you have Bison 2.4 first and just do `make`.

First produce the SMV format version form a full PDDL file containing both domain and problem instance:

```bash
./pddl2smv < examples/basic4.pddl > examples/basic4.smv
```

Next run NuSMV using `-dynamic` (otherwise it is too slow):

```bash
~/opt/nusmv-2.6.0/bin/NuSMV -dynamic examples/basic4.smv
```

Or using the latest nuXmv:

```bash
~/opt/nuXmv-2.0.0-Linux/bin/nuXmv -dynamic examples/smv/basic4.smv
```

The output would be:

```bash
[ssardina@Thinkpad-X1 pddl2smv]$ ~/opt/nuXmv-2.0.0-Linux/bin/nuXmv -dynamic examples/smv/basic4.smv 
*** This is nuXmv 2.0.0 (compiled on Mon Oct 14 17:48:12 2019)
*** Copyright (c) 2014-2019, Fondazione Bruno Kessler
*** For more information on nuXmv see https://nuxmv.fbk.eu
*** or email to <nuxmv@list.fbk.eu>.
*** Please report bugs at https://nuxmv.fbk.eu/bugs
*** (click on "Login Anonymously" to access)
*** Alternatively write to <nuxmv@list.fbk.eu>.

*** This version of nuXmv is linked to NuSMV 2.6.0.
*** For more information on NuSMV see <http://nusmv.fbk.eu>
*** or email to <nusmv-users@list.fbk.eu>.
*** Copyright (C) 2010-2019, Fondazione Bruno Kessler

*** This version of nuXmv is linked to the CUDD library version 2.4.1
*** Copyright (c) 1995-2004, Regents of the University of Colorado

*** This version of nuXmv is linked to the MiniSat SAT solver. 
*** See http://minisat.se/MiniSat.html
*** Copyright (c) 2003-2006, Niklas Een, Niklas Sorensson
*** Copyright (c) 2007-2010, Niklas Sorensson

*** This version of nuXmv is linked to MathSAT
*** Copyright (C) 2009-2019 by Fondazione Bruno Kessler
*** Copyright (C) 2009-2019 by University of Trento and others
*** See http://mathsat.fbk.eu

-- specification !( F environment.holding_A)  is false
-- as demonstrated by the following execution sequence
Trace Description: LTL Counterexample 
Trace Type: Counterexample 
  -> State: 1.1 <-
    environment.on_A_A = FALSE
    environment.on_A_C = FALSE
    environment.on_A_B = FALSE
    environment.on_A_D = FALSE
    environment.on_C_A = FALSE
    environment.on_C_C = FALSE
    environment.on_C_B = FALSE
    environment.on_C_D = FALSE
    environment.on_B_A = FALSE
    environment.on_B_C = FALSE
    environment.on_B_B = FALSE
    environment.on_B_D = FALSE
    environment.on_D_A = FALSE
    environment.on_D_C = FALSE
    environment.on_D_B = FALSE
    environment.on_D_D = FALSE
    environment.ontable_A = FALSE
    environment.ontable_C = FALSE
    environment.ontable_B = FALSE
    environment.ontable_D = FALSE
    environment.clear_A = FALSE
    environment.clear_C = FALSE
    environment.clear_B = FALSE
    environment.clear_D = FALSE
    environment.handempty = FALSE
    environment.holding_A = FALSE
    environment.holding_C = FALSE
    environment.holding_B = FALSE
    environment.holding_D = FALSE
    agent.action = start_action
  -> State: 1.2 <-
    environment.ontable_A = TRUE
    environment.ontable_C = TRUE
    environment.ontable_B = TRUE
    environment.ontable_D = TRUE
    environment.clear_A = TRUE
    environment.clear_C = TRUE
    environment.clear_B = TRUE
    environment.clear_D = TRUE
    environment.handempty = TRUE
    agent.action = pick-up_A
  -> State: 1.3 <-
    environment.ontable_A = FALSE
    environment.clear_A = FALSE
    environment.handempty = FALSE
    environment.holding_A = TRUE
    agent.action = stack_A_B
  -- Loop starts here
  -> State: 1.4 <-
    environment.on_A_B = TRUE
    environment.clear_A = TRUE
    environment.clear_B = FALSE
    environment.handempty = TRUE
    environment.holding_A = FALSE
    agent.action = pick-up_C
  -> State: 1.5 <-
    environment.ontable_C = FALSE
    environment.clear_C = FALSE
    environment.handempty = FALSE
    environment.holding_C = TRUE
    agent.action = put-down_C
  -> State: 1.6 <-
    environment.ontable_C = TRUE
    environment.clear_C = TRUE
    environment.handempty = TRUE
    environment.holding_C = FALSE
    agent.action = pick-up_C
```


# Credits


* Created: October 2010
* Author: Fabio Patrizi
* e-mail: f.patrizi@imperial.ac.uk, patrizi@dis.uniroma1.it

Refactored and cleaned-up by Sebastian Sardina.