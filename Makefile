BDIR = bin
IDIR = include
ODIR = obj
SDIR = src

CC = gcc
CFLAGS = -g -Wall -std=c99 -I$(IDIR)
LFLAGS = -lm

PROG = $(BDIR)/genlist

_DEPS = elmlist.h list.h outils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS= elmlist.o list.o main.o outils.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

.PHONY : run all dirs clean delete

run : $(PROG)
	./$(PROG)

$(PROG) : dirs $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

dirs :
	@mkdir -p $(ODIR)
	@mkdir -p $(BDIR)

$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(ODIR) core

delete : clean
	rm -rf $(BDIR)