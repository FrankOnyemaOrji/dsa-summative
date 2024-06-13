# Compress makefile
#author: Frank Onyema Orji
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable name
EXEC = compress

# Source files
SRCS = main.c huffman.c file_ops.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = huffman.h file_ops.h

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(EXEC) $(OBJS)

# Phony targets
.PHONY: all clean
