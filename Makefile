PROG=main.exe
CC=gcc
SOURCES=main.c calculator.c shapes.c calculator_handlers.c shape_handlers.c rock_paper_scissors.c
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


# PROG=main.exe
# CC=gcc
# SOURCES=main.c calculator.c shapes.c calculator_handlers.c shape_handlers.c
# CFLAGS=-g -Wall -Werror -std=c99
# DEPS=shapes.h calculator.h calculator_handlers.h shape_handlers.h
# OBJS=$(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

# TEST_PROG=test.exe
# TEST_SOURCES=$(wildcard tests/*.c)
# TEST_OBJS=$(addprefix $(TEST_OUTPUTDIR)/,$(TEST_SOURCES:.c=.o))

# ifeq ($(DEBUG), 1)
# 	CFLAGS += -g
# 	OUTPUTDIR=bin/debug
# 	TEST_OUTPUTDIR=bin/debug_tests
# 	PROG=programmet-debug.exe
# else
# 	CFLAGS += -g0 -O3
# 	OUTPUTDIR=bin/release
# 	TEST_OUTPUTDIR=bin/release_tests
# endif

# OBJS = $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

# $(PROG): $(OUTPUTDIR) $(OBJS)
# 	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

# $(OUTPUTDIR)/%.o: %.c $(DEPS)
# 	$(CC) $(CFLAGS) -o $@ -c $<

# # Test-related rules
# $(TEST_PROG): $(TEST_OUTPUTDIR) $(TEST_OBJS)
# 	$(CC) $(CFLAGS) -o $(TEST_PROG) $(TEST_OBJS)

# $(TEST_OUTPUTDIR)/%.o: %.c $(DEPS)
# 	$(CC) $(CFLAGS) -o $@ -c $<

# $(TEST_OUTPUTDIR):
# 	@mkdir "$(TEST_OUTPUTDIR)"

# test: $(TEST_PROG)
# 	./$(TEST_PROG)

# clean:
# 	@del /q "$(OUTPUTDIR)"
# 	@del /q "$(TEST_OUTPUTDIR)"
# 	@del /q $(PROG)
# 	@del /q $(TEST_PROG)

# $(OUTPUTDIR):
# 	@mkdir "$(OUTPUTDIR)"

# .PHONY: clean test