DEBUG=yes
ifeq ($(DEBUG),yes)
	CXXFLAGS=-std=c++98 -Wall -Wextra -pedantic -g
else
	CXXFLAGS=-std=c++98 -march=native -O2
endif

LDFLAGS= -pthread -lIce -lIceUtil -lIceStorm -lvlc    
CXX= g++
OBJ_DIR=obj/
SRC_DIR=src/
#INCLUDE_DIR=include/
INCLUDE=include/
LIB_DIR=IceLib/
BIN_DIR=bin/

SRC=$(wildcard $(SRC_DIR)*.cpp)
SRC_BIS=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC))
OBJ=$(SRC_BIS:.cpp=.o)

EXE=$(BIN_DIR)metaServeur

all: $(EXE)

#sliceJava: interface.ice
#	slice2java --output-dir Slicejava interface.ice

slice: interface.ice
	slice2cpp $< && mv interface.cpp $(SRC_DIR) && mv interface.h $(INCLUDE)

$(EXE): $(OBJ) main.cpp
	$(CXX) $(CXXFLAGS)  $^ $(LDFLAGS) -o $@ -I $(INCLUDE)  -L $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE)%.h
	$(CXX) $(CXXFLAGS)  -c $< -o $@ -I $(INCLUDE)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ_DIR)*.o

mrproper: clean
	rm -f $(EXE)


# $@: the target filename.
# $*: the target filename without the file extension.
# $<: the first prerequisite filename.
# $^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
# $+: similar to $^, but includes duplicates.
# $?: the names of all prerequisites that are newer than the target, separated by spaces.
