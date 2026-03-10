all:
	as main.s -o main.o
	ld main.o -o main

ans:
	as ans_main.s -o main.o
	ld main.o -o main

clean:
	find . ! -name 'README.md' ! -name 'ans_main.s' ! -name 'main.s' ! -name 'Makefile' -type f -exec rm -f {} +