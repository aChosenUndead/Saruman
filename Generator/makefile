GRI_H_DIR = ../Grimoire/src
INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib
CC		= g++
CFLAGS	= -Wall -W -ansi -pedantic -g -O0 -std=c++11 -I $(INC_DIR) -I $(GRI_H_DIR)
ARCHIVE = ar
linux: generator.a
libmonstergenerator.a: $(INC_DIR)/generator.h $(SRC_DIR)/generator.cpp
	@echo "\nCreating Generator library in $(LIB_DIR)/$@ ...\n"
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/generator.cpp -o $(OBJ_DIR)/generator.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/generator.o 
	@echo "\n Generator library created!\n"
clean:
	@echo "Removing .o and binary/executable files...\n"
	@rm -rf $(OBJ_DIR)/*