# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lSDL2

TARGET = particles
SRCS = main.cc screen.cc
OBJS = $(SRCS:.cc=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile .cc files into .o files
%.o: %.cc
	$(CC) -c $(CFLAGS) $< -o $@

# Clean the project (remove object files and executable)
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean