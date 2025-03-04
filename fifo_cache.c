#include "cache.h"

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
int cache_lookup(int** lengths_and_prices, int number_of_options, int rod_length, int* optimal_cut_for_length);

// ==== INITIALIZE_CACHE ==== //
// Initializes an empty cache // 
// ========================== // 

void initialize_cache(int_func_ptr* assigned_provider){

    original_provider = *assigned_provider;
    *assigned_provider = cache_lookup; 

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

int cache_lookup(int** lengths_and_prices, int number_of_options, int rod_length, int* optimal_cut_for_length) {
    
    FIFOCacheEntry* current = FIFO_cache->head; 

    while(current != NULL){
        if(current->key == rod_length) {
            return current->value; 
        }
        current = current->next; 
    }

    // If not in cache, call the original provider
    int result = (*original_provider)(lengths_and_prices, number_of_options, rod_length, optimal_cut_for_length);
    
    // If cache is full, evict entry at head of list
    if (FIFO_cache->size == FIFO_cache->capacity) { 
        FIFOCacheEntry* evict_entry = FIFO_cache->head; 
        FIFO_cache->head = FIFO_cache->head->next; 
        FIFO_cache->evictions++; 
        free(evict_entry); 
        FIFO_cache->size--; 
    }

    // Create a new entry to store the key and value
    FIFOCacheEntry* new_entry = (FIFOCacheEntry*)malloc(sizeof(FIFOCacheEntry)); 
    new_entry->key = rod_length; 
    new_entry->value = result; 
    new_entry->next = NULL; 


    // If list is empty, new entry is both head and tail of the list 
    if(FIFO_cache->head == NULL){
        FIFO_cache->head = new_entry;  
        FIFO_cache->tail = new_entry; 
    } else {    // Tail points to the new entry
        FIFO_cache->tail->next = new_entry; 
        FIFO_cache->tail = new_entry; 
    }

    FIFO_cache->size++; 
    return result;
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

    printf("\n");
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