CFLAGS  = -Wall -Wextra -Wpedantic -Werror

UNITY   = ../Unity/src/unity.c
SRC     = src/sum.c
TEST    = test/test_sum.c

all: testing
	@gcc $(SRC) src/main.c -o main
	@echo "Main build completed!"

testing:
	@gcc $(CFLAGS) $(UNITY) $(SRC) $(TEST) -o test_runner
	@echo "Running tests..."
	@./test_runner

clean:
	rm -f test_runner main

.PHONY: all main testing clean
