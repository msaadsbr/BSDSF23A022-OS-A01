# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source and object files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/mystrfunctions.c $(SRC_DIR)/myfilefunctions.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Output binary
TARGET = $(BIN_DIR)/client

# Default target
all: $(TARGET)

# Link rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
