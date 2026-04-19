CC = gcc
CFLAGS = -Wall -Wextra 

main: clean
	$(CC) $(CFLAGS) tree.c main.c -o main 

tests: clean
	$(CC) $(CFLAGS) tree.c tests.c ../Unity/src/unity.c -o tests 

clean:
	rm -f *.o main tests