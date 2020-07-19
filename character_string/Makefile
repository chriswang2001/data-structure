sources = *.c
target = string
CC = gcc
CCFLAG = -g -Wall -fsanitize=address

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)