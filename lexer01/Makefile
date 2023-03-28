CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = build
SRC = main.c
EXE = main

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o