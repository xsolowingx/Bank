#Some variables are used with a special mean:
#$@ name of the target
#$^ list with the names of all Pre-requisite without duplicates
#$< name of the first Pre-requisite
#variables of compiling.
CC = g++
CFLAGS = -W -Wall -pedantic -ansi -O0 -g -std=c++11 -I. -I$(INC_DIR)
#variables of directories.
INC_DIR = ./include
BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./build
#object variable
OBJECT = $(OBJ_DIR)/operation.o $(OBJ_DIR)/account.o $(OBJ_DIR)/main.o $(OBJ_DIR)/bank.o
#Headers
ARQ_H = $(INC_DIR)/operation.h $(INC_DIR)/account.h $(INC_DIR)/bank.h


all:	$(OBJECT)
	@echo "========================"
	@echo "*Conecting the target*"
	@echo "=========*-*============"
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/Bank
	@echo "+++[executable Bank create in $(BIN_DIR)] +++"
	@echo "=========*-*============"

$(OBJ_DIR)/operation.o:	$(SRC_DIR)/operation.cpp $(ARQ_H)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/account.o:	$(SRC_DIR)/account.cpp $(ARQ_H)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o:	$(SRC_DIR)/main.cpp $(ARQ_H)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/bank.o:	$(SRC_DIR)/bank.cpp $(ARQ_H)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/Bank
	rm -rf $(OBJ_DIR)/*.o