# Makefile

# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -g

# Executable name
TARGET = rods

# Common Object files
OBJS = rods.o read_print_file.o make_print_cut_list.o

# Shared Library for dynamic loading 
LRU_LIB = lru_cache.so
FIFO_LIB = fifo_cache.so

# Default target
all: $(TARGET) $(LRU_LIB) $(FIFO_LIB)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile object files
read_print_file.o: read_print_file.c read_print_file.h constants.h
	$(CC) $(CFLAGS) -c read_print_file.c -o read_print_file.o

make_print_cut_list.o: make_print_cut_list.c constants.h
	$(CC) $(CFLAGS) -c make_print_cut_list.c -o make_print_cut_list.o

rods.o: rods.c cache.h read_print_file.h make_print_cut_list.h
	$(CC) $(CFLAGS) -c rods.c -o rods.o

# Compile LRU cache as a shared library
$(LRU_LIB): lru_cache.o
	$(CC) -shared -o $(LRU_LIB) lru_cache.o

lru_cache.o: lru_cache.c cache.h
	$(CC) $(CFLAGS) -c -fPIC lru_cache.c -o lru_cache.o

# Compile FIFO cache as a shared library
$(FIFO_LIB): fifo_cache.o
	$(CC) -shared -o $(FIFO_LIB) fifo_cache.o

fifo_cache.o: fifo_cache.c cache.h
	$(CC) $(CFLAGS) -c -fPIC fifo_cache.c -o fifo_cache.o

clean:
	rm -f $(OBJS) $(TARGET) $(LRU_LIB) $(FIFO_LIB) lru_cache.o fifo_cache.o

