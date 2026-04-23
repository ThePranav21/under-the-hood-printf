CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.c fart.c
	$(CC) $(CFLAGS) -o main main.c fart.c

clean:
	rm -f main