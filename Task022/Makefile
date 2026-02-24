CFLAGS  = -Wall -Wextra -Wpedantic -Werror

UNITY   = ../Unity/src/unity.c
SRC     = src/resistance.c
TEST    = test/test_resistance.c

all: testing
	@gcc $(SRC) src/main.c -o main -lm
	@echo "Main build completed!"

testing:
	@gcc $(CFLAGS) $(UNITY) $(SRC) $(TEST) -o test_runner -lm
	@echo "Running tests..."
	@./test_runner

clean:
	rm -f test_runner main

.PHONY: all testing clean