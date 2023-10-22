BDIR = bin
IDIR = include
ODIR = obj
SDIR = src

CC = gcc
# Le déboggage en toutes circonstances grâce à :: -D _DEBUG_
# que l'on peutarêter à tout moment grâce à :: -U _DEBUG_
CFLAGS = -Wall -I$(IDIR) -U _DEBUG_
LFLAGS = -lm 

PROG = $(BDIR)/form

_DEPS = list_elm.h list.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS = list_elm.o list.o main.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

.PHONY : run all dirs clean delete

run : all
	./$(PROG)

all : dirs $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LFLAGS)

dirs :
	@mkdir -p $(ODIR)
	@mkdir -p $(BDIR)

$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(ODIR) core

delete : clean
	rm -rf $(BDIR)