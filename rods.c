#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <dlfcn.h>
#include "read_print_file.h"
#include "make_print_cut_list.h"
#include "constants.h"
#include "cache.h"

// Function prototypes // 
void solve_rods(int** lengths_and_prices, int number_of_options, int rod_length); 
int solve_rods_recursive(int** lengths_and_prices, int number_of_options, int rod_length, int* optimal_cut_for_length);
set_provider_fnc load_cache_module(const char *module_path); 

// Function pointers // 
int_func_ptr assigned_provider = NULL;  

// Define provider functions
provider_set providers = {
    .assigned_provider = solve_rods_recursive, 
    .reset_data = NULL,
    .print_data = NULL,
    .free = NULL
};

// ===== MAIN ======= //
int main(int argc, char *argv[]) {

    if (argc < 2){
        printf("Failed to provide a file name");
        return 1; 
    }

    if (argc == 3) {
        set_provider_fnc set_provider = load_cache_module(argv[2]);
        if (set_provider) {
            set_provider(&providers);
        } else {
            fprintf(stderr, "Failed to set cache provider from module.\n");
            return 1;
        }
    }

    FILE *lengths_prices_file = fopen(argv[1], "r");
    if (lengths_prices_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int** lengths_and_prices = NULL;  
    int number_of_options = 0; 
    int rod_length = 0; 

    char buffer[MAX_INPUT_LENGTH]; 
    int parsed_char_count = 0; 

    read_lengths_prices_file(lengths_prices_file, &lengths_and_prices, &number_of_options); 
    // DEBUG
    //display_lengths_and_prices(lengths_and_prices, number_of_options);

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (sscanf(buffer, "%d%n", &rod_length, &parsed_char_count) != 1 || buffer[parsed_char_count] != '\0') {
            printf("Rod length must be a positive integer\n");
            continue;
        }

        if(rod_length < 0){
            printf("Invalid input. Enter a positive value.\n");
            continue; 
        }

        solve_rods(lengths_and_prices, number_of_options, rod_length); 

        // DEBUG
        /*
        if(providers.print_data){
            printf("Printing cache\n");
            providers.print_data();
          }
        */

        if(providers.reset_data){
            providers.reset_data();
        }
        
    }
    
    if (providers.free) {
        printf("Freeing allocated memory\n");
        providers.free();
    }

    return 0; 
}

// ============= SOLVE_RODS ============ //
// This function initializes an array    //
// to solve the rod cutting problem, and //
// calls the recursive rod cutting       //
// algorithm function.                   //
//                                       //
// Then generates the cut list           //
// and prints the final solution.        //
// ======================================//

void solve_rods(int** lengths_and_prices, int number_of_options, int rod_length) {
    
    int* optimal_cut_for_length = (int*)malloc((rod_length + 1) * sizeof(int));
    for (int current_length = 0; current_length <= rod_length; current_length++) {
        optimal_cut_for_length[current_length] = -1;  
    }

    (providers.assigned_provider)(lengths_and_prices, number_of_options, rod_length, optimal_cut_for_length);

    Cut_list optimal_cut_list = generate_optimal_cut_list(optimal_cut_for_length, rod_length, lengths_and_prices, number_of_options); 
    print_cut_list(optimal_cut_list); 

    free(optimal_cut_for_length);
}

// ====== SOLVE_RODS_RECURSIVE========== //
// Recursive solution to the rod cutting //
// problem.                              // 
//                                       //
// Output parameter: an array which      // 
// stores the best cut to make for any   //
// given rod length.                     //
// ======================================//

int solve_rods_recursive(int** lengths_and_prices, int number_of_options, int rod_length, int* optimal_cut_for_length) {
    
    if (rod_length == 0) {
        return 0; 
    }

    int max_profit = 0;

    for (int ix = 0; ix < number_of_options; ix++) {
        int cut_length = lengths_and_prices[ix][CUT_LENGTH_INDEX];
        int cut_price = lengths_and_prices[ix][CUT_PRICE_INDEX];

        if (cut_length <= rod_length) {
            int current_profit = cut_price + (providers.assigned_provider)(lengths_and_prices, number_of_options, rod_length - cut_length, optimal_cut_for_length);
            if (current_profit > max_profit) {
                max_profit = current_profit;
                optimal_cut_for_length[rod_length] = cut_length;
            }
        }
    }

    return max_profit;
}

// ========= LOAD_CACHE_MODULE =========== //
// Loads the cache module and returns the  //
// function pointer to set_provider.       //
// ======================================= //


set_provider_fnc load_cache_module(const char *module_path) {
    void* handle = dlopen(module_path, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Failed to load library: %s\n", dlerror());
        return NULL;
    }

    set_provider_fnc set_provider = (set_provider_fnc) dlsym(handle, "set_provider");
    if (!set_provider) {
        fprintf(stderr, "Failed to load function 'set_provider': %s\n", dlerror());
        dlclose(handle);
        return NULL;
    }

    return set_provider;
}
