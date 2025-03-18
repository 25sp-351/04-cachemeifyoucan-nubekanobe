#include "read_print_file.h"

/********* READ_LENGTHS_PRICES_FILE *********/
/* This function reads pairs of cut lengths */
/* and prices and stores them in an array   */
/*                                          */        
/* Output parameters: Pointer to a 2d array */
/* and an integer value which stores the    */
/* number of length,price pairs             */  
/********************************************/

void read_lengths_prices_file(FILE* lengths_prices_file, int*** lengths_and_prices, int* number_of_options){

    char buffer[MAX_INPUT_LENGTH]; 

    while (fgets(buffer, sizeof(buffer), lengths_prices_file) != NULL) {
        (*number_of_options)++;
    }

    (*lengths_and_prices) = malloc(*number_of_options * sizeof(int*)); 

    for (int ix = 0; ix < *number_of_options; ix++) {
        (*lengths_and_prices)[ix] = malloc(CUT_OPTION_ENTRIES * sizeof(int)); 
    }

    rewind(lengths_prices_file); 

    for (int ix = 0; ix < *number_of_options; ix++){
        fscanf(lengths_prices_file, "%d,%d", &(*lengths_and_prices)[ix][CUT_LENGTH_INDEX], &(*lengths_and_prices)[ix][CUT_PRICE_INDEX]); 
    }
}


/*******DISPLAY_LENGTHS_AND_PRICES******/
/* This function displays information  */
/* entered by the user for DEBUG       */
/***************************************/

void display_lengths_and_prices(int** lengths_and_prices, int number_of_options){

    printf("\nLengths and Prices Entered\n");
    printf("=========================\n\n");

    for (int current_cut = 0; current_cut < number_of_options; current_cut++){
       printf("Length: %d, Price: %d\n", lengths_and_prices[current_cut][CUT_LENGTH_INDEX], lengths_and_prices[current_cut][CUT_PRICE_INDEX]);   
    }
}