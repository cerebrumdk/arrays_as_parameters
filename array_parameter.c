/*
 * A program to check different ways of passing different arrays as parameters
 * 
 * TLTR: 
 * When parameter is 1D arr, you can pass it in any way 
 * and it's gonna propagate both through indexes and pointer notation
 *
 * 
 * When parameter is multiD array, you can pass it as you want BUT
 * 
 * to use multiD indexing [][] you need to pass pointer to the row or whole array
 * but this way you loose reusability 
 * (now you can use this func only with arrays of this specific size)
 *
 * to pass multiD arr of ANY size, you will need to pass a pointer to arr's <data_type> element
 * but then you won't be able to index it as a multiD array
 * The reason is your func doesn't know it's multiD, 
 * for the func it's just a pointer to a single static contiguous block of memory)
 */

#include <stdio.h>
#include <stdlib.h>
#include "array_as_parameters.h"
#define ONED_ARR_SIZE 3
#define ROWS_TWOD_ARR 3
#define COLS_TWOD_ARR 3

void oneD_arr_variations(void);

void multiD_arr_variations(void);

void dynamic_1Darr_variations(void);

void multiD_dynamic_arr_variations(void);

void stat_arrOFptrs_variations(void);

// declaring main with parameters for no reason like a big boy
int main(int argc, char **argv)
{

	oneD_arr_variations();		
	multiD_arr_variations();
	dynamic_1Darr_variations();
	multiD_dynamic_arr_variations();
	stat_arrOFptrs_variations();

	return 0;
}

void oneD_arr_variations()
{
	/*
	 * Initializing and passing one_D array in different forms to respective methods
	 */

	// I know it may take non-trivial time if arr is big,
	// but for me it's better than accidental UB
	int arr[ONED_ARR_SIZE] = {0}; 
	initialize_1D_arr(ONED_ARR_SIZE, arr);

	printf("ONE dimensional array in differnet form of parameter of a function\n");
	printf("Size of the arr[%d]: %lu bytes\n", ONED_ARR_SIZE, sizeof(arr));
	printf("Size of an array as a parameter, p_1Darr_PtrInt: %d bytes\n", 
						oneDarr_asPtr_toINT(ONED_ARR_SIZE, arr));
	printf("size of a pointer is: %lu bytes \n\n", sizeof(int*));

	oneDarr_asPtr_toWholeArr(ONED_ARR_SIZE, &arr);
}

void multiD_arr_variations()
{
	/*
	 * Initializing and passing multi_D array in different forms to respective methods
	 */

	int multi_arr[ROWS_TWOD_ARR][COLS_TWOD_ARR] = {0};

	printf("MULTI dimensional arrays as parameters\n");
	
	initialize_2D_arr(ROWS_TWOD_ARR, COLS_TWOD_ARR, *multi_arr);
	
	multiArr_asPtr_toINT(multi_arr[0]); // pointer to the int value

	multiArr_asPtr_toROW(multi_arr);

	multiArr_asPtr_toWhole(&multi_arr);

}

void dynamic_1Darr_variations()
{
	/*
	 * Initializing and passing dynamic 1D array in different forms to respective methods
	 */
	int *dynamic_1Darr = NULL;
	
	// I decided to always typecast void pointers for the sake of portability
	dynamic_1Darr = (int*)malloc(ONED_ARR_SIZE*sizeof(int));
	if (dynamic_1Darr == NULL){
		fprintf(stderr, "sorry lad, no allocation for u\n");
		exit(1);
	}
	initialize_1D_arr(ONED_ARR_SIZE, dynamic_1Darr);
		
	// ahaha what the hell am I doing
	int (*dyn1D_as_row)[ONED_ARR_SIZE] = NULL;
	dyn1D_as_row = (int (*)[ONED_ARR_SIZE])malloc(sizeof(int[ONED_ARR_SIZE])); 
	if (dyn1D_as_row == NULL){
		fprintf(stderr, "Your ptr to dynamic row isn't allocated brobro");
		exit(1);
	}
	// *dyn1D_as_row is a pointer to the first value
	initialize_1D_arr(ONED_ARR_SIZE, *dyn1D_as_row);


	printf("ONE Dimansional DYNAMIC array as a param\n");
	f_dynamic1Darr(ONED_ARR_SIZE, dynamic_1Darr);
	f_dyn1D_as_row(ONED_ARR_SIZE, dyn1D_as_row);

	free(dynamic_1Darr);
	dynamic_1Darr = NULL;

	// it should be simply dyn1D_as_row, cause brackets and shit are the type it points to,
	// and plain pointer is the addrs itself, I think :D 
	free(dyn1D_as_row);
	dyn1D_as_row == NULL;
}

void multiD_dynamic_arr_variations()
{
	/* 
	 * Initializing and passing dynamic 1D array in different forms to respective methods
	 */
	
	int i = 0, j = 0;
	
	printf("MultiD dynamic arr as a param\n");

	int **multi_dyn_arr = NULL;
	multi_dyn_arr = (int **)malloc(ROWS_TWOD_ARR*sizeof(int*));
	if(multi_dyn_arr == NULL){
		fprintf(stderr, "No multi_dyn_arr for u man\n");
		exit(1);
	}
	printf("multi_dyn_arr\n");
	initialize_2D_dynamic_arr(ROWS_TWOD_ARR, COLS_TWOD_ARR, multi_dyn_arr);
	
	int (*multi_dyn_rows)[COLS_TWOD_ARR] = NULL; 
	multi_dyn_rows = (int (*)[COLS_TWOD_ARR])malloc(ROWS_TWOD_ARR*sizeof(int[COLS_TWOD_ARR]));
	if(multi_dyn_rows == NULL){
		fprintf(stderr, "I'm tired of this experiment, make it stop\n");
		exit(1);
	}
	printf("multi_dyn_rows\n");
	// Despite being dynamically allocated, it's basically a atatic 2D arr 
	initialize_2D_arr(ROWS_TWOD_ARR, COLS_TWOD_ARR, *multi_dyn_rows);

	f_2D_dynamic_arr(ROWS_TWOD_ARR, COLS_TWOD_ARR, multi_dyn_arr);
	f_dyn2D_static_rows(ROWS_TWOD_ARR, COLS_TWOD_ARR, multi_dyn_rows);
	f_dyn2D_static_rows_asPtr_toINT(ROWS_TWOD_ARR, COLS_TWOD_ARR, *multi_dyn_rows);

	for(i = 0; i < ROWS_TWOD_ARR; i++){
		free(multi_dyn_arr[i]);
	}
	free(multi_dyn_arr);
	multi_dyn_arr = NULL;

	// Since it got only one allocation, we can free it right away
	free(multi_dyn_rows);
	multi_dyn_rows = NULL;
}

void stat_arrOFptrs_variations()
{
	/* 
	 * Initializing and passing static array of pointers as parameter
	 *
	 * Just wanted to check either it passes as **arr, and tired to make separate initializer
	 */
	
	int arr1[] = {1, 2 ,3};
	int arr2[] = {4, 5, 6};
	int arr3[] = {7, 8, 9};

	int *arr_ofPointers_toArrs[ONED_ARR_SIZE] = {arr1, arr2, arr3};
	
	printf("Static array of pointers\n");
	f_stat_arr_of_ptrs_as_double_ptr(ONED_ARR_SIZE, arr_ofPointers_toArrs);
	// Yeah, I can't figure out how to turn it into a row form
	// f_stat_arrOfPtr_as_row(ONED_ARR_SIZE, ptr_toarr_of_pointers);
}

