CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = main.c array.c
TEST_SRC = array.c test_array.c ../../../bdz/Unity/src/unity.c

TARGET = main
TEST_TARGET = test_main

UNITY_INC = ../../../bdz/Unity/src

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

test: $(TEST_SRC)
	$(CC) $(CFLAGS) -I$(UNITY_INC) -o $(TEST_TARGET) $(TEST_SRC)

run-tests: test
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)