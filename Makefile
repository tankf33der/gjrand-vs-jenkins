all: c
	gcc -O3 jsf32.c jsf32.out
c:
	rm -rf *.o *.out
