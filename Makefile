IDIR = include
ODIR = obj
SDIR = src
BDIR = bin

CC = gcc
CFLAGS = -Wall -I$(IDIR) -c
LDFLAGS = -lm

PROG=$(BDIR)/mat

_DEPS = vector.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS= main.o vector.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

.PHONY : run all dirs clean delete

run : all
	./$(PROG)

all : dirs $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)

$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

dirs :
	@mkdir -p $(ODIR) $(BDIR)

clean :
	rm -rf $(ODIR) core

delete : clean
	rm -rf $(BDIR)
