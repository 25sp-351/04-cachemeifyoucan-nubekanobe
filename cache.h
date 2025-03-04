#ifndef CACHE_H
#define CACHE_H

#include <stdio.h> 
#include <stdlib.h>

#define CACHE_CAPACITY 100
#define NOT_PRESENT -1

typedef int KeyType;
typedef int ValueType;

typedef int (*int_func_ptr)(int** lengths_and_prices, int number_of_options, int rod_length, int* optimal_cut_for_length);  
extern int_func_ptr assigned_provider;  

void initialize_cache(int_func_ptr* original_provider_function); 
void print_cache(); 
void free_cache();


#endif