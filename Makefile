all: c
	gcc -O3 -Wall -Wextra -pedantic jsf.c -o jsf.out
c:
	rm -rf *.o *.out
