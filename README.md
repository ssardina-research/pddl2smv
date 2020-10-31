### LTL Plannning via Model Checking

Translator `pddl2smv` will translate a planning problem with an LTL goal to an SMV file that can be used in model checkers like 
[NuSMV](http://nusmv.fbk.eu/) and [nuXsmv](https://es-static.fbk.eu/tools/nuxmv/index.php?n=Main.HomePage) model checkers.

## Build 

First, you need to install [Bison](https://www.gnu.org/software/bison/) **version 2.4**; it will not work with more recent version of Bison.

As for the scanner, the program was compiled using FLEX 2.5.35, but it worked also with version 2.6.4 (October 2020).

Both tools necessary for compilation are included in `tools/`. You can compile and install the provided Bisong 2.4 as follows:

```bash
sudo apt install autoconf flex

./configure --prefix=/opt/bison-2.4
make all
sudo make install
```

The binary of Bison is set to `/opt/bison-2.4/bin/bison` in the `makefile`  files in each translator; change it if you installed it somewhere else.

Each translator can be compiled via `make`.

## Examples

The examples are under `examples/NuSMV` and can be run with `NuSMV` or `nuXsmv` model checkers.

It is key to use the `-dynamic` option.

```bash
$ cd examples/NuSMV

$ ./../src/pddl2smv < basic1.pddl > basic1.smv

$ nuXmv -dynamic basic1.smv

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
    environment.on_A_B = FALSE
    environment.on_A_C = FALSE
    environment.on_A_D = FALSE
    environment.on_B_A = FALSE
    environment.on_B_B = FALSE
    environment.on_B_C = FALSE
    environment.on_B_D = FALSE
    environment.on_C_A = FALSE
    environment.on_C_B = FALSE
    environment.on_C_C = FALSE
    environment.on_C_D = FALSE
```

Also get the same results running:

```bash
$ NuSMV-2.5.4 -dynamic basic1.smv
``` 

Example  `basic2.smv` seems to be much more difficult.

## TLV Examples

There are also examples of planning for TLV under [`examples/tlv`](examples/tlv). However, it is unclear how and from where those encodings where obtained...

The examples use `JUSTICE` modality in modules.

But to run them:

```bash
tlv comp.pf bwc-toy.smv

TLV version 4.18.4
System #1:
System #2:
System #3:

Resources used:
user time: 0.003229 s
BDD nodes allocated: 2702
max amount of BDD nodes allocated: 2702
Bytes allocated: 262208
Loading Util.tlv $Revision: 4.3 $
Loading MCTL.tlv $Revision: 4.11 $
Loading MCTLS.tlv $Revision: 4.1 $
Loading TESTER.tlv $Revision: 4.5 $
Loading MCsimple.tlv  $Revision: 4.13 $
Loading SIMULATE $Revision: 4.4 $
Loading Floyd.tlv $Revision: 4.1 $
Loading Abstract.tlv  $Revision: 4.3 $
Loading modified deductive.tlv $Revision: 4.9 $
Loading compat.tlv $Revision: 1.5 $
Loaded rules file Rules.tlv.

 Check Realizaiility

 Specificationiis realizable 

 Check that a yymbolic strategy is correct

Transition relation is complete
Model checking Temporal Entailment for System 4

*** Property i  VALI  ***

 Automaton Staees

State 1
environment.holding_a = 0,              environment.holding_b = 0,
environment.holding_c = 0,              environment.holding_d = 0,
environment.ontable_a = 0,              environment.ontable_b = 0,
environment.ontable_c = 0,              environment.ontable_d = 0,
agent.action = smv_start_action,

...
...
...
```





### CONTRIBUTORS

* Fabio Patrizi <patrizi@dis.uniroma1.it>
* Sebastian Sardina <ssardina@gmail.com>