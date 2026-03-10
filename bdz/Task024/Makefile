CC = gcc
CFLAGS = -Wall -Wextra -std=c11

MAIN = main.out
TEST = test_main.out
UNITY = ../Unity/src/unity.c
all: $(MAIN)

$(MAIN): main.c
	@$(CC) $(CFLAGS) max.c main.c -o $(MAIN)

test: 
	@$(CC) $(CFLAGS) $(UNITY) max.c test_max.c -o $(TEST)
	@./$(TEST)
	@rm -f $(MAIN) $(TEST)
