all:
	as -g main.s -o main.o
	ld main.o -o main
clean:
	find . ! -name 'README.md' ! -name 'main.s' ! -name 'Makefile' -type f -exec rm -f {} +