CC = gcc
CFLAGS = -Wall -Wextra -std=c11

MAIN = main.exe
TEST = test_main.exe

ifeq ($(OS),Windows_NT)
else
    MAIN = main
    TEST = test_main
endif

all: $(MAIN)

$(MAIN): main.c
	@$(CC) $(CFLAGS) main.c -o $(MAIN)

test: $(MAIN) test_main.c
	@$(CC) $(CFLAGS) test_main.c -o $(TEST)
	@$(TEST)
	@rm -f $(MAIN) $(TEST)
