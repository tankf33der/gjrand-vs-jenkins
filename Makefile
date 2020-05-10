all: c
	gcc -O3 jsf.c -o jsf.out
c:
	rm -rf *.o *.out
