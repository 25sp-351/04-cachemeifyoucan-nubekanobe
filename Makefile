# Makefile

# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -g

# Executable name
TARGET_L = rodslru
TARGET_F = rodsfifo

# Common Object files
COMMON_OBJS = rods.o read_print_file.o make_print_cut_list.o

# Cache specific object files 
LRU_OBJS = $(COMMON_OBJS) lru_cache.o 
FIFO_OBJS = $(COMMON_OBJS) fifo_cache.o

# Default target
all: $(TARGET_L) $(TARGET_F)

# Compile rodsl (LRU)
$(TARGET_L): $(LRU_OBJS)
	$(CC) $(CFLAGS) $(LRU_OBJS) -o $(TARGET_L)

# Compile rodsf (FIFO)
$(TARGET_F): $(FIFO_OBJS)
	$(CC) $(CFLAGS) $(FIFO_OBJS) -o $(TARGET_F)

# Compile object files
fifo_cache.o: fifo_cache.c cache.h
	$(CC) $(CFLAGS) -c fifo_cache.c -o fifo_cache.o

lru_cache.o: lru_cache.c cache.h
	$(CC) $(CFLAGS) -c lru_cache.c -o lru_cache.o

read_print_file.o: read_print_file.c read_print_file.h constants.h
	$(CC) $(CFLAGS) -c read_print_file.c -o read_print_file.o

make_print_cut_list.o: make_print_cut_list.c constants.h
	$(CC) $(CFLAGS) -c make_print_cut_list.c -o make_print_cut_list.o

rods.o: rods.c cache.h read_print_file.h make_print_cut_list.h
	$(CC) $(CFLAGS) -c rods.c -o rods.o

# Clean up build files
clean:
	rm -f $(LRU_OBJS) $(FIFO_OBJS) $(TARGET_L) $(TARGET_F)

