debug ?= 0
NAME := TermGraph
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
LIB_DIR := lib
TESTS_DIR := tests
BIN_DIR := bin

OBJS := $(patsubst %.c,%.o, $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIB_DIR)/**/*.c))

CC=gcc
CFLAGS := -std=gnu17 -Wall -Wextra -pedantic
LDFLAGS := -lm

$(NAME): all $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $(patsubst %, build/%, $(OBJS)) $(LDFLAGS)

$(OBJS): dir
	@mkdir -p $(BUILD_DIR)/$(@D)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(BUILD_DIR)/$@ -c $*.c

# Setup build and bin directories
dir:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

# Clean build and bin directories
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all
