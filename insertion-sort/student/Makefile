CC=gcc
EXEC=tests
LDFLAGS=-lcunit
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

%.o: %.c
	$(CC) -Wall -Werror -D C99 -std=gnu99 -c -o $@ $< 

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

run:
	./tests

.PHONY: run
