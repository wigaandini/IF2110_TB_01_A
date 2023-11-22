# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-Wall -g

# Target executable name
TARGET=tes

# Source files
SRCS=main.c \
     adt/configmachine.c \
     adt/charmachine.c \
     adt/liststatikuser.c \
     adt/listdin.c \
     adt/matrix.c \
     adt/friendmatrix.c \
     adt/pcolor.c \
     adt/prioreqfollinked.c \
     adt/listdinkicauan.c \
     adt/datetime.c \
     adt/time.c \
     adt/wordmachine.c \
     adt/stack.c \
     adt/draf.c \
     adt/listlinierutas.c \
     adt/prioqueuetime.c \
     adt/treebalasan.c \

# Object files
OBJECTS=$(SRCS:.c=.o)

# Build target executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Generic rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET) $(OBJECTS)

# Rule for rebuilding
rebuild: clean $(TARGET)
