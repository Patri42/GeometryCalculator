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

SOURCES=$(addprefix src/, main.c calculator.c shapes.c calculator_handlers.c shape_handlers.c utils.c rock_paper_scissors.c game_data.c)
DEPS=$(addprefix include/, calculator.h shapes.h calculator_handlers.h shape_handlers.h utils.h rock_paper_scissors.h game_data.h)
OBJS =  $(addprefix $(OUTPUTDIR)/,$(notdir $(SOURCES:.c=.o)))

TEST_SOURCES=test_shapes.cpp test_calculator.cpp test_rock_paper_scissors.cpp test_main.cpp
TEST_OBJS =  $(addprefix $(OUTPUTDIR)/,$(TEST_SOURCES:.cpp=.o))

all: debug

debug: $(PROG)

release: 
	$(MAKE) DEBUG=0

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: src/%.c $(DEPS)
	$(CC) $(CFLAGS) -I include -o $@ -c $< 

$(OUTPUTDIR)/%.o: tests/%.cpp
	$(CXX) $(CFLAGS) -I include -o $@ -c $<

clean:
	@del /q "$(OUTPUTDIR)"
	@del /q $(PROG)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

check.exe: $(TEST_OBJS) $(filter-out $(OUTPUTDIR)/main.o, $(OBJS))
	$(CXX) -o $@ $^ $(CFLAGS) -I $(GTESTINCLUDE) $(LIBGTEST)

test: check.exe
	./check.exe

.PHONY: clean debug release test