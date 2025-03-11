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
ValueType cache_lookup(int** data_array, int array_size, KeyType key, int* solution_array);
void update_cache_entry_access_time(int index);
void evict_lru_entry(KeyType key, ValueType result);
void add_cache_entry(KeyType key, ValueType result);
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

ValueType cache_lookup(int** data_array, int array_size, KeyType key, int* solution_array) {

    for (int ix = 0; ix < LRU_cache->size; ix++){
        if (LRU_cache->entry[ix].key == key){
            update_cache_entry_access_time(ix);
            return LRU_cache->entry[ix].value; 
        }
    }

    ValueType result = (*original_provider)(data_array, array_size, key, solution_array);

    if (LRU_cache->size == LRU_cache->capacity) {
        evict_lru_entry(key, result);
    } else {
        add_cache_entry(key, result);
    }

    return result;
}

// === FUNCTIONS TO SUPPORT CACHE LOOKUP === //                         
// update_cache_entry_access_time            //
// evict_lru_entry                           //
// add_cache_entry                           // 
// ==========================================//

void update_cache_entry_access_time(int index) {
    LRU_cache->entry[index].last_access_time = LRU_cache->time_counter++;
}

void evict_lru_entry(KeyType key, ValueType result) {
    int lru_index = find_index_of_lru_entry();

    if (lru_index < 0 || lru_index >= LRU_cache->capacity) {
        fprintf(stderr, "Error: Invalid LRU index during eviction.\n");
        return;
    }

    LRU_cache->entry[lru_index].key = key;
    LRU_cache->entry[lru_index].value = result;
    update_cache_entry_access_time(lru_index);
    LRU_cache->evictions++;
}

void add_cache_entry(KeyType key, ValueType result) {

    if (LRU_cache->size >= LRU_cache->capacity) {
        fprintf(stderr, "Error: Cache is full. Entry not added.\n");
        return;
    }

    LRU_cache->entry[LRU_cache->size].key = key;
    LRU_cache->entry[LRU_cache->size].value = result;
    update_cache_entry_access_time(LRU_cache->size);
    LRU_cache->size++;
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