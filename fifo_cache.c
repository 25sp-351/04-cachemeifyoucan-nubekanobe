#include "cache.h"
#include <stdio.h>
#include <stdlib.h> 

typedef struct FIFOCacheEntry {
    KeyType key;
    ValueType value;
    struct FIFOCacheEntry* next; 
    
} FIFOCacheEntry;

typedef struct FIFOCache {
    FIFOCacheEntry* head; 
    FIFOCacheEntry* tail; 
    int size; 
    int capacity; 
    int evictions; 

} FIFOCache; 

// Initialize cache pointer
FIFOCache* FIFO_cache = NULL;

// Function pointers to store original providers //
int_func_ptr original_provider = NULL;

// FIFO Cache Function prototypes //
void initialize_cache();  
ValueType cache_lookup(int** data_array, int array_size, KeyType key, int* solution_array);
void add_cache_entry(KeyType key, ValueType result); 
void evict_cache_head_entry(); 
void print_cache();
void free_cache();
void reset_cache(); 

// ========= SET_PROVIDER_FUNCTION ======= //
// Sets the assigned provider to the cache //
// provider functions.                    //
// ======================================= //

void set_provider(provider_set *provider) {
  
    original_provider = provider->assigned_provider; 
    provider->assigned_provider = cache_lookup; 

    provider->free = free_cache;
    provider->print_data = print_cache; 
    provider->reset_data = reset_cache; 

    initialize_cache();
}


// ==== INITIALIZE_CACHE ==== //
// Initializes an empty cache // 
// ========================== // 

void initialize_cache(){

    if (FIFO_cache != NULL) {
        free(FIFO_cache);  
    }
    
    FIFO_cache = (FIFOCache*)malloc(sizeof(FIFOCache));

    FIFO_cache->head = NULL; 
    FIFO_cache->tail = NULL; 
    FIFO_cache->size = 0; 
    FIFO_cache->evictions = 0; 
    FIFO_cache->capacity = CACHE_CAPACITY;  
}

// =========== CACHE_LOOK_UP ======== // 
// Searches the cache to determine    //
// if a value has previously been     //
// stored for a given key, and returns//
// it to the caller.                  //
//                                    //
// If the value has not been stored,  //
// calls the original provider to     //
// compute the value.                 //
//                                    //
// If the cache is full, evicts the   //
// head entry and adds the new entry  //
// to the end of the list.            //
// ================================== // 

ValueType cache_lookup(int** data_array, int array_size, KeyType key, int* solution_array) {
    
    FIFOCacheEntry* current = FIFO_cache->head; 

    while(current != NULL){
        if(current->key == key) {
            return current->value; 
        }
        current = current->next; 
    }

    // If not in cache, call the original provider
    ValueType result = (*original_provider)(data_array, array_size, key, solution_array);
    
    // If cache is full, evict entry at head of list
    if (FIFO_cache->size == FIFO_cache->capacity) { 
        evict_cache_head_entry();
    }

    add_cache_entry(key, result); 

    return result;
}

// ==== EVICT_CACHE_HEAD_ENTRY == // 
// Removes the element which was  //
// inserted first (FIFO)          //
// ============================== //

void evict_cache_head_entry() {
    FIFOCacheEntry* evict_entry = FIFO_cache->head;
    FIFO_cache->head = FIFO_cache->head->next;
    FIFO_cache->evictions++;
    free(evict_entry); // Free the evicted entry's memory
    FIFO_cache->size--;
}

// ======= ADD_CACHE_ENTRY ==== // 
// Add entry to the end of the  //
// cache.                       // 
// =============================// 

void add_cache_entry(KeyType key, ValueType result) {
    FIFOCacheEntry* new_entry = (FIFOCacheEntry*)malloc(sizeof(FIFOCacheEntry));
    new_entry->key = key;
    new_entry->value = result;
    new_entry->next = NULL;

    // If the list is empty, the new entry becomes both head and tail
    if (FIFO_cache->head == NULL) {
        FIFO_cache->head = new_entry;
        FIFO_cache->tail = new_entry;
    } else { // Otherwise, add to the tail of the list
        FIFO_cache->tail->next = new_entry;
        FIFO_cache->tail = new_entry;
    }

    FIFO_cache->size++;
}

// ====== PRINT_CACHE (FOR DEBUG) ======== // 
// Prints all cache entries:               // 
// KEY, VALUE                              // 
// ======================================= // 

void print_cache() {
    printf("Cache Contents (Size: %d/%d):\n", FIFO_cache->size, FIFO_cache->capacity);
    
    FIFOCacheEntry* current = FIFO_cache->head;
    while (current != NULL) {
        printf("Key = %d, Value = %d\n", current->key, current->value);
        current = current->next;
    }

    printf("Evictions: %d\n", FIFO_cache->evictions); 
}

// ============== FREE_CACHE ============== // 
// Free memory allocated for cache          // 
// ======================================== // 

void free_cache() {
    if (FIFO_cache) {
        FIFOCacheEntry* current = FIFO_cache->head;

        while (current != NULL) {
            FIFOCacheEntry* temp = current;
            current = current->next;
            free(temp);
        }
        free(FIFO_cache);
        FIFO_cache = NULL;
    }
}

// ============== RESET_CACHE ============= // 
// Reset cache for each new computation     // 
// ======================================== // 

void reset_cache() {
    if (!FIFO_cache) return;

    FIFOCacheEntry* current = FIFO_cache->head;
    while (current != NULL) {
        FIFOCacheEntry* temp = current;
        current = current->next;
        free(temp);  // Free each cache entry
    }

    FIFO_cache->head = NULL;
    FIFO_cache->tail = NULL;
    FIFO_cache->size = 0;
    FIFO_cache->evictions = 0;
}