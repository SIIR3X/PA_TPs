BDIR = bin
IDIR = include
ODIR = obj
SDIR = src

CC = gcc
CFLAGS = -Wall -I$(IDIR) -c
LDFLAGS = -lm

PROG = $(BDIR)/reloaded

_DEPS = matrix.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS = matrix.o main.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

.PHONY : run all dirs clean delete

run : $(PROG)
	./$(PROG) data/A.txt data/B.txt

$(PROG) : dirs $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LFLAGS)

dirs :
	@mkdir -p $(ODIR) $(BDIR)

$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

clean :
	rm -rf $(ODIR) core

delete : clean
	rm -rf $(BDIR)