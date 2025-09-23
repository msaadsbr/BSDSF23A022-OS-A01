# src/Makefile
CC = gcc
CFLAGS = -Wall -I../include

OBJ_DIR = ../obj
BIN_DIR = ../bin
LIB_DIR = ../lib
TARGET = $(BIN_DIR)/client_static

MAIN_SRC = main.c
MAIN_OBJ = $(OBJ_DIR)/main.o

LIBS = -L$(LIB_DIR) -lmyutils

.PHONY: all client_static clean

all: client_static

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# compile main.c into obj/main.o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# link main.o with static library to produce client_static
client_static: $(MAIN_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN_OBJ) $(LIBS)

clean:
	-rm -f $(MAIN_OBJ) $(TARGET)
