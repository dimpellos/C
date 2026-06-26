# Compiler
CC = gcc

# Compiler flags: 
CFLAGS = -Wall -Wextra -std=c11 -O2

# Source files
SRCS = main.c buffer.c termio_utils.c game.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = hangman

# Default rule to build executable
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file into .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# New 'play' target: build and run the game
play: $(TARGET)
	./$(TARGET)

.PHONY: all clean play
