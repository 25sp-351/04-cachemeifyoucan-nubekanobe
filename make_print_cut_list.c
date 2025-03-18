#include <stdio.h> 
#include "make_print_cut_list.h"

/********* GENERATE_OPTIMAL_CUT_LIST***********/
/* Aggregates final results of the rod        */ 
/* cutting problem into a struct              */  
/* Generates and returns struct to the caller */
/**********************************************/

Cut_list generate_optimal_cut_list(int* optimal_cut_for_length, int rod_length, int** lengths_and_prices, int number_of_options) {
    
    Cut_list result = {0}; 

    result.rod_length = rod_length; 
    result.num_options = number_of_options; 
    result.remainder = rod_length;
    result.lengths_and_prices_p = lengths_and_prices; 
    
    while (rod_length > 0) {
        int cut_length = optimal_cut_for_length[rod_length];

        if (cut_length == -1) {  
            break; 
        }

        for (int current_option = 0; current_option < number_of_options; current_option++) {
            if (lengths_and_prices[current_option][CUT_LENGTH_INDEX] == cut_length) {
                result.best_cut_counts[current_option]++;
                result.total_value += lengths_and_prices[current_option][CUT_PRICE_INDEX];
                break;
            }
        }

        result.remainder -= cut_length;
        rod_length -= cut_length;
    }

    return result;
}

/************** PRINT_CUT_LIST **************/
/* Outputs the final results of the rod     */
/* cutting problem                          */  
/********************************************/

void print_cut_list(Cut_list optimal_cut_list) {
    
    for (int current_option = 0; current_option < optimal_cut_list.num_options; current_option++) {
        if (optimal_cut_list.best_cut_counts[current_option] > 0) {
            int length = optimal_cut_list.lengths_and_prices_p[current_option][CUT_LENGTH_INDEX];
            int price = optimal_cut_list.lengths_and_prices_p[current_option][CUT_PRICE_INDEX];
            printf("%d @ %d = %d\n", optimal_cut_list.best_cut_counts[current_option], length, optimal_cut_list.best_cut_counts[current_option] * price);
        }
    }

    printf("Remainder = %d\n", optimal_cut_list.remainder);
    printf("Value = %d\n", optimal_cut_list.total_value);
}