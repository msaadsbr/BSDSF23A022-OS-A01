# src/Makefile
CC = gcc
CFLAGS = -Wall -I../include

OBJ_DIR = ../obj
BIN_DIR = ../bin
LIB_DIR = ../lib

MAIN_SRC = main.c
MAIN_OBJ = $(OBJ_DIR)/main.o

STATIC_LIB = $(LIB_DIR)/libmyutils.a
DYNAMIC_LIB = $(LIB_DIR)/libmyutils.so

STATIC_TARGET = $(BIN_DIR)/client_static
DYNAMIC_TARGET = $(BIN_DIR)/client_dynamic

.PHONY: all client_static client_dynamic clean

all: client_static client_dynamic

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

client_static: $(MAIN_OBJ) $(STATIC_LIB) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(STATIC_TARGET) $(MAIN_OBJ) -L$(LIB_DIR) -lmyutils

client_dynamic: $(MAIN_OBJ) $(DYNAMIC_LIB) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(DYNAMIC_TARGET) $(MAIN_OBJ) -L$(LIB_DIR) -lmyutils

clean:
	-rm -f $(MAIN_OBJ) $(STATIC_TARGET) $(DYNAMIC_TARGET)

