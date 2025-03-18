#ifndef CACHE_H
#define CACHE_H


#define CACHE_CAPACITY 100
#define NOT_PRESENT -1

typedef int KeyType;
typedef int ValueType;

typedef ValueType (*int_func_ptr)(int**, int, KeyType key, int*);  
typedef void (*void_function)(void);

typedef struct {
    int_func_ptr assigned_provider;
    void_function reset_data; 
    void_function print_data;
    void_function free; 
} provider_set;

// Function prototype for dynamically loading cache module
typedef void (*set_provider_fnc)(provider_set *provider);
set_provider_fnc load_cache_module(const char *module_path);

#endif
