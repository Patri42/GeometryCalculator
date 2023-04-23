PROG=main.exe
CC=gcc
CXX=g++
CFLAGS=-Wall -Werror
DEBUG?=1
GTESTINCLUDE = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR=bin/debug
	PROG=programmet-debug.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
	PROG=programmet.exe
endif

SOURCES=main.c calculator.c shapes.c calculator_handlers.c shape_handlers.c utils.c rock_paper_scissors.c game_data.c
DEPS=calculator.h shapes.h calculator_handlers.h shape_handlers.h utils.h rock_paper_scissors.h game_data.h
OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

$(OUTPUTDIR)/test_shapes.o: test_shapes.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	@del /q "$(OUTPUTDIR)"
	@del /q $(PROG)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

check.exe: $(OUTPUTDIR)/test_shapes.o $(filter-out $(OUTPUTDIR)/main.o, $(OBJS))
	$(CXX) -o $@ $^ $(CFLAGS) -I $(GTESTINCLUDE) $(LIBGTEST)

test: check.exe
	./check.exe

.PHONY: clean