# lib/Makefile
CC = gcc
CFLAGS = -Wall -I../include -fPIC

SRC_DIR = ../src
OBJ_DIR = ../obj
LIB_DIR = ../lib

SRCS = mystrfunctions.c myfilefunctions.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

STATIC_LIB = $(LIB_DIR)/libmyutils.a
DYNAMIC_LIB = $(LIB_DIR)/libmyutils.so

.PHONY: all static dynamic clean

all: static dynamic

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

static: $(STATIC_LIB)
$(STATIC_LIB): $(OBJS) | $(LIB_DIR)
	ar rcs $@ $(OBJS)
	ranlib $@

dynamic: $(DYNAMIC_LIB)
$(DYNAMIC_LIB): $(OBJS) | $(LIB_DIR)
	$(CC) -shared -o $@ $(OBJS)

clean:
	-rm -f $(OBJ_DIR)/*.o $(STATIC_LIB) $(DYNAMIC_LIB)

