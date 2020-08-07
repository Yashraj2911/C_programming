FLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRCS))
PROGRAM=poker

$(PROGRAM): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	gcc -c $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(PROGRAM) *~

cards.o: cards.h
deck.o: deck.h
eval.o: eval.h
future.o:future.h
input.o: input.h
main.o: main.c
poker.o: cards.o
poker.o: deck.o
poker.o: eval.o
poker.o: future.o
poker.o: input.o
poker.o: main.o
