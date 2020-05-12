all: c
	gcc -O3 -Wall -Wextra -pedantic jsf.c -o jsf.out
	gcc -O3 -Wall -Wextra -pedantic pcg32-minimal.c -o pcg32-minimal.out
c:
	rm -rf *.o *.out
