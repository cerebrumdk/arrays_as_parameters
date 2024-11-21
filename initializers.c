#include <stdio.h>
#include <stdlib.h>

void initialize_1D_arr(int size, int *arr)
{
	/*
	 * Initializes 1-dimansional arrays
	 */
	
	int i = 0;

	for(i = 0; i < size; i++){
		arr[i] = i + 1;	
	}
}

void initialize_2D_arr(int rows_2Darr, int cols_2Darr, int *arr)
{
	/*
	 * Initializes and prints 2D array
	 * without indexing, since we are losing type data of rows and columns 
	 * to account for all possible 2D arrays
	 */
	int i = 0;
	// int j = 0;
	// int count = 1;

	printf("Your 2D array:\n");
	for(i = 0; i < (rows_2Darr*cols_2Darr); i++){
		if((i % cols_2Darr) == 0){
			printf("{ ");
		}
		// Actually this whole thing won't work,
		// it's way easier to initialize it as 1D arr
		// I will leave it be as a reminder
		// for(j = 0; j < cols_2Darr; j++){
			
			// error: lvalue required as left operand of assignment
			// *(arr + i) + j = count++;
			// and now that I think about it, it was a stupid thing to do
			
			// This works perfectly
		//	*(arr + i*j) = count++;
		//	printf("[%d] ", *(arr + i*j));
		//}
		arr[i] = i + 1;
		printf("[%d] ", arr[i]);
		
		if(((i + 1) % cols_2Darr) == 0){
			printf("}\n");
		}
	}
	printf("\n");
}

// The problem with multiD array initializer is 
// I can't do a single function that initializes both
// static and dynamic arrays, since dynamic multiD arrays are
// multi pointers, so to say 
void initialize_2D_dynamic_arr(int rows_dyn2D, int cols_dyn2D, int **arr)
{
	/*
	 * Initializes and prints out 2D dynamic arrays
	 */

	int i = 0, j = 0;
	int count = 1;

	printf("Here's your 2D dynamic array:\n");
	for(i = 0; i < rows_dyn2D; i++){
		arr[i] = (int *)malloc(cols_dyn2D*sizeof(int));
		if(arr[i] == NULL){
			fprintf(stderr, "Failed to allocate memory for a row of a 2D dynamic array arr[%d]", i);
			exit(1);	
		}
		printf("{ ");
		for(j = 0; j < cols_dyn2D; j++){
			arr[i][j] = count++;
			printf("[%d] ", arr[i][j]);
		}
		printf("}\n");
	}
	printf("\n");
}

