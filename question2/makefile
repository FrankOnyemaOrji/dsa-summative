# Makefile for compiling and executing the student sorting program
#author: Frank Onyema Orji
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = student_sort

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c

clean:
	rm -f $(TARGET) $(TARGET).o

.PHONY: all clean
