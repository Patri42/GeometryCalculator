PROG=main.exe
CC=gcc
CFLAGS=-g -Wall -Werror -std=c99
DEPS = 
OBJ = main.o shapes.o calculator.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)