sources = *.c
target = graph
CC = gcc
CCFLAG = -g -Wall -fsanitize=address

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target) main_graph.c