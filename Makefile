################################################################################
# Variables
#
CC := gcc
CFLAGS := -std=c99 -g -Wall -Wextra -Wpedantic
LDFLAGS := -lm

SRC_DIR := src
BIN_DIR := bin
HDR_DIR := lib

TARGETS := recursion linked_lists
HEADERS := ch02
################################################################################
# Builds
#
all: $(addprefix $(BIN_DIR)/, $(TARGETS))

${BIN_DIR}/%: ${SRC_DIR}/%.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(addprefix $(HDR_DIR)/, $(HEADERS)).c

rec: ${BIN_DIR}/recursion
link: ${BIN_DIR}/linked_lists

clean:
	rm $(BIN_DIR)/*

.PHONY: all clean rec link
