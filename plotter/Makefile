#DIR_FONTS = ./Fonts
DIR_OBJ = ./obj
DIR_BIN = ./bin
DIR_DATA = ./data

OBJ_C = $(wildcard ${DIR_OBJ}/*.cpp)
OBJ_O = $(patsubst %.cpp,${DIR_BIN}/%.o,$(notdir ${OBJ_C}))

#INC_PATH = ${DIR_OBJ}/inc
#INC_COMMON = -I ${INC_PATH}/*.hpp
#INC_TXTRD = -I ${INC_PATH}

TARGET = Plotter
#BIN_TARGET = ${DIR_BIN}/${TARGET}

CC = g++

DEBUG = -g -O0 -Wall
LINKER = -z muldefs
CFLAGS += $(DEBUG) 

ARC = ${DIR_ARC}/libads1256.a
LIB = -lstdc++ -lpython2.7 -lrt -lm 

all: ${TARGET} $makecsv

${TARGET}:${OBJ_O}
	$(CC) $(CFLAGS) $(LINKER) $(OBJ_O) -o $@  $(LIB)

${DIR_BIN}/%.o : $(DIR_OBJ)/%.cpp $(DIR_OBJ)/%.hpp
	$(CC) $(CFLAGS) -c  $< -o $@  $(LIB)

${DIR_BIN}/%.o : $(DIR_OBJ)/%.cpp
	$(CC) $(CFLAGS) -c  $< -o $@  $(LIB)
	
$makecsv : 
	touch ${DIR_DATA}/akashi.csv

clean :
	rm $(DIR_BIN)/*.* 
	rm $(TARGET) 
