#ifndef READ_PRINT_FILE_H
#define READ_PRINT_FILE_H

// Function prototypes // 
void read_lengths_prices_file(FILE* lengths_prices_file, int*** lengths_and_prices, int* number_of_options); 
void display_lengths_and_prices(int** lengths_and_prices, int number_of_options); 

#endif