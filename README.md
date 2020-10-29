# PDDL to SMV translators

This is a collection of translator from pddl format to SMV format for model checkers and game solvers (for synthesis).

They are all based on Fabio Patrizi first version to translate PDDL files that can be used with:
* [TLV](https://github.com/ssardina-planning/tlv) and [NuGAT](https://github.com/ssardina-planning/nugat-0.6.0), and [JTVL](http://jtlv.ysaar.net/) game solvers. 
* [NuSMV](http://nusmv.fbk.eu/) and [nuXsmv](https://es-static.fbk.eu/tools/nuxmv/index.php?n=Main.HomePage) model checkers.

## Build and installs

First, you need to install [Bison](https://www.gnu.org/software/bison/) **version 2.4**; it will not work with more recent version of Bison.

As for the scanner, the program was compiled using FLEX 2.5.35, though other versions might work as well.

Both tools necessary for compilation are included in `tools/`. You can compile and install the provided Bisong 2.4 as follows:

```bash
./configure --prefix=/opt/bison-2.4
make all
sudo make install
```

The binary of Bison is set to `/opt/bison-2.4/bin/bison` in the `makefile`  files in each translator; change it if you installed it somewhere else.

Each translator can be compiled via `make`.

## Translators available

### LTL Plannning via Model Checking

Translator `pddl2smv` will translate a planning problem with an LTL goal to an SMV file that can be used in model checkers like NuSMV or nuXsmv. Check the [README.md](pddl2smv/README.md)

### Agent Planning Programs via Reactive Synthesis 

Translators `pp2tlv`, `pp2jltv`, and `pp2nugat`, will translate an agent planning program (APP) specified in APP-PDDL format (either version v1 or v2) to an SMV encoding under a safety goal.

These APP-PDDL to SMV translators were used for experimentation in the following article:

* Giuseppe De Giacomo, Alfonso Gerevini, Fabio Patrizi, Alessandro Saetti, and Sebastian Sardina. [Agent planning programs](http://www.sciencedirect.com/science/article/pii/S0004370215001563). Artificial Intelligence, 231:64--106, 2016.

### CONTRIBUTORS

* Fabio Patrizi <patrizi@dis.uniroma1.it>
* Sebastian Sardina <ssardina@gmail.com>