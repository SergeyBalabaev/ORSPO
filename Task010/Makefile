CC = gcc
CFLAGS = -Wall -Wpedantic -Werror
TARGET = main
SOURCES = main.c
OBJECTS = main.o

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)