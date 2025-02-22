#ifndef MAKE_PRINT_CUT_LIST_H
#define MAKE_PRINT_CUT_LIST_H

#include "constants.h"

typedef struct {
    int rod_length; 
    int best_cut_counts[MAX_CUT_OPTIONS];      
    int total_value;      
    int remainder; 
    int num_options; 
    int** lengths_and_prices_p;       

} Cut_list; 

// Function prototypes // 
Cut_list generate_optimal_cut_list(int* optimal_cut_for_length, int rod_length, int** lengths_and_prices, int number_of_options);
void print_cut_list(Cut_list optimal_cut_list);  

#endif