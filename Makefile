CC = gcc
CFLAGS = -Wall -std=c99

all: opsys_lab2

opsys_lab2: opsys_lab2.c
	$(CC) $(CFLAGS) -o opsys_lab2 opsys_lab2.c

clean:
	rm -f opsys_lab2
