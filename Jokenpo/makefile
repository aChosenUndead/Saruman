INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib
CC		= g++
CFLAGS	= -Wall -pedantic -ansi -I $(INC_DIR) -W -g -std=c++11
ARCHIVE = ar
linux: jokenpo.a
libjokenpo.a: $(INC_DIR)/jokenpo.h $(SRC_DIR)/jokenpo.cpp 
	@echo "\nCreating jokenpo library in $(LIB_DIR)/$@ ...\n"
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/jokenpo.cpp -o $(OBJ_DIR)/jokenpo.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/jokenpo.o 
	@echo "\nJokenpo library created!\n"
clean:
	@echo "Removing .o and binary/executable files...\n"
	@rm -rf $(OBJ_DIR)/*