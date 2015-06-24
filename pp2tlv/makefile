CC=g++
CFLAGS=-c -Wall
LDFLAGS=

FLEX_SRC=grammar.lex
FLEX_OUT=lex.yy.c

BISON_SRC=grammar.yy
BISON_OUT=grammar.tab.cc
BISON_HDR= grammar.tab.hh location.hh position.hh stack.hh

SOURCES=ast.cpp planprog.cpp planprog2tlv.cpp symtable.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o) $(FLEX_OUT:.c=.o) $(BISON_OUT:.tab.cc=.tab.o)
EXECUTABLE=pp2tlv

all: bison flex $(EXECUTABLE)

flex: $(FLEX_OUT)

$(FLEX_OUT): $(FLEX_SRC) $(BISON_OUT)
	flex $(FLEX_SRC)

bison: $(BISON_OUT)

$(BISON_OUT): $(BISON_SRC)
	/opt/bison-2.4/bin/bison $(BISON_SRC)
	
.cpp.o .cc.o .c.o:
	$(CC) $(CFLAGS) $< -o $@

	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

	
.PHONY : clean
clean:
	rm -rf $(OBJECTS) $(FLEX_OUT) $(BISON_OUT) $(BISON_HDR)
	
