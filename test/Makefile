CC = clang
CFLAGS = -O3 -std=c11 -Wall -pedantic

SRC = $(wildcard *.c)
SRC += $(wildcard ../*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

.PHONY: build all clean

build: test.out

all: clean build

clean::
		rm -rf $(DEP)
		rm -rf $(OBJ)
		rm -rf *.out

test: test.out
		./test.out

test.out: $(OBJ)
		clang $(CFLAGS) -o $@ $^

-include $(DEP)

%.d: %.c
		$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@
