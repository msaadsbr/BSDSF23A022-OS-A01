# lib/Makefile
CC = gcc
CFLAGS = -Wall -I../include

SRC_DIR = ../src
OBJ_DIR = ../obj
LIB_DIR = ../lib
LIBNAME = libmyutils.a

# source files that should go into the static library
SRCS = mystrfunctions.c myfilefunctions.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(LIB_DIR)/$(LIBNAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# compile each src file into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# create static library from objects
$(LIB_DIR)/$(LIBNAME): $(OBJS) | $(LIB_DIR)
	@echo "Archiving $@ ..."
	ar rcs $@ $(OBJS)
	# ranlib ensures archive index (safe to call)
	ranlib $@

clean:
	-rm -f $(OBJS)
	-rm -f $(LIB_DIR)/$(LIBNAME)
