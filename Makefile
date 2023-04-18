PROG=main.exe
CC=gcc
SOURCES=main.c calculator.c shapes.c calculator_handlers.c shape_handlers.c
CFLAGS=-g -Wall -Werror -std=c99
DEPS=shapes.h calculator.h calculator_handlers.h shape_handlers.h
OBJS=$(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR=bin/debug
	PROG=programmet-debug.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
endif
 
OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS) 
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	@del /q "$(OUTPUTDIR)" 
	@del /q $(PROG)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

.PHONY: clean