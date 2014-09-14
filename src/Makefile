OBJS = nlang.o parser.o lex.o LinkedList.o
bindir = /usr/bin/
GCC = $(bindir)gcc
MAKE=$(bindir)make
RM=rm
# CFLAGS = -O2
CFLAGS = -O0 -g -Wall -I../include

all: nlang

nlang: $(OBJS)
	$(GCC) -o nlang $(OBJS)

%.o: %.c
	$(GCC) $(CFLAGS) -c $*.c

clean:
	$(RM) -rf *.o
	$(RM) -rf nlang
