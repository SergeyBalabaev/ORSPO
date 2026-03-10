# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -g

# Пути
SRC = src/calc.c src/main.c
TEST_SRC = tests/test_calc.c ../Unity/src/unity.c

# Цели
all: main test

# Сборка main
main: $(SRC)
	$(CC) $(CFLAGS) -o main.out $(SRC)

# Сборка и запуск тестов
test: $(TEST_SRC) src/calc.c
	$(CC) $(CFLAGS) -o test.out $(TEST_SRC) src/calc.c
	./test.out

# Очистка
clean:
	rm -f *.out
