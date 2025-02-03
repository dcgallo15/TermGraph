CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11
OBJDIR=obj
LIBS=./res

OUT=graph

make:
	$(CC) -o $(OUT) src/main.c -I$(LIBS) $(CFLAGS)

