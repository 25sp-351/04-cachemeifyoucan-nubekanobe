#include "cache.h"

typedef struct LRUCacheEntry {
    KeyType key;
    ValueType value;
    int last_access_time;

} LRUCacheEntry;

typedef struct LRUCache {

    LRUCacheEntry* entry; 
    int size; 
    int capacity; 
    int evictions; 
    int time_counter;

} LRUCache; 

// LRU Cache Function Prototypes //
int cache_lookup(int** lengths_and_prices, int number_of_options, int rod_length, int* optimal_cut_for_length);
int find_index_of_lru_entry();

// Initialize cache pointer
LRUCache* LRU_cache = NULL;  

// Function pointers to store original providers //
int_func_ptr original_provider = NULL;

// ==== INITIALIZE_CACHE ==== //
// Initializes an empty cache // 
// ========================== // 

void initialize_cache(int_func_ptr* assigned_provider) {

    original_provider = *assigned_provider;
    *assigned_provider = cache_lookup; 


    if (LRU_cache != NULL) {
        free(LRU_cache);  
    }
    
    LRU_cache = (LRUCache*)malloc(sizeof(LRUCache));

    LRU_cache->size = 0; 
    LRU_cache->capacity = CACHE_CAPACITY; 
    LRU_cache->time_counter = 0; 
    LRU_cache->evictions = 0; 

    LRU_cache->entry = (LRUCacheEntry*)malloc(sizeof(LRUCacheEntry) * LRU_cache->capacity);
    
    for(int ix = 0; ix < LRU_cache->capacity; ix++){
        LRU_cache->entry[ix].key = -1; 
        LRU_cache->entry[ix].value = -1; 
        LRU_cache->entry[ix].last_access_time = 0; 

    }
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
// LRU entry, and replaces it. If the //
// cache has space, adds the key and  //
// value to the next available entry. //
// ================================== // 

int cache_lookup(int** lengths_and_prices, int number_of_options, int rod_length, int* optimal_cut_for_length) {
    
    for (int ix = 0; ix < LRU_cache->size; ix++){
        if (LRU_cache->entry[ix].key == rod_length){
            LRU_cache->entry[ix].last_access_time = LRU_cache->time_counter++;
            return LRU_cache->entry[ix].value; 
        }
    }

    // If not in cache, call the original provider
    int result = (*original_provider)(lengths_and_prices, number_of_options, rod_length, optimal_cut_for_length);
    
    if (LRU_cache->size == LRU_cache->capacity) { // if cache is full 
        int lru_index = find_index_of_lru_entry();
        
        LRU_cache->entry[lru_index].key = rod_length;
        LRU_cache->entry[lru_index].value = result;
        LRU_cache->entry[lru_index].last_access_time = LRU_cache->time_counter++;
        LRU_cache->evictions++; 

    } else {
        LRU_cache->entry[LRU_cache->size].key = rod_length;
        LRU_cache->entry[LRU_cache->size].value = result;
        LRU_cache->entry[LRU_cache->size].last_access_time = LRU_cache->time_counter++;
        LRU_cache->size++;
    }

    return result;
}

// ====== FIND_INDEX_OF_LRU_ENTRY ======== // 
// Searches the cache to determine the     //
// least recently used entry, based on     //
// last_access_time. Returns the index of  //
// that entry.                             // 
// ======================================= // 

int find_index_of_lru_entry() {
    int lru_index = -1;
    int lowest_time = INT_MAX;

    for (int ix = 0; ix < LRU_cache->size; ix++) {
        if (LRU_cache->entry[ix].last_access_time < lowest_time) {
            lowest_time = LRU_cache->entry[ix].last_access_time;
            lru_index = ix;
        }
    }
    
    return lru_index;
}

// ====== PRINT_CACHE (FOR DEBUG) ======== // 
// Prints all cache entries:               // 
// KEY, VALUE, and LAST_ACCESS_TIME.       // 
// ======================================= // 

void print_cache() {
    printf("Cache Contents (Size: %d/%d):\n", LRU_cache->size, LRU_cache->capacity);
    for (int ix = 0; ix < LRU_cache->size; ix++) {
        printf("Entry %d: Key = %d, Value = %d, Last Access Time = %d\n", 
                ix + 1, 
                LRU_cache->entry[ix].key, 
                LRU_cache->entry[ix].value, 
                LRU_cache->entry[ix].last_access_time);
    }

    printf("Evictions: %d\n", LRU_cache->evictions); 
    printf("\n");
}

// ============== FREE_CACHE ============== // 
// Free memory allocated for cache          // 
// ======================================== // 

void free_cache() {
    if (LRU_cache) {
        free(LRU_cache->entry);
        free(LRU_cache);
        LRU_cache = NULL; 
    }
}