CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -O2
LIB = libstronk.a
OBJ = stronklib.o

.PHONY: all lib main test clean

all: main test

lib: $(LIB)

$(OBJ): stronk.c
	$(CC) -c stronk.c -o $(OBJ)

$(LIB): $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

main: lib main.c
	$(CC) main.c -L. -lstronk -o main

test: lib test.c
	$(CC) test.c -L. -lstronk -o test

clean:
	rm -f *.o *.a main test
