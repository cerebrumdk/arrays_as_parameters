/*
 * Functions that take multiD dynamic arrays as
 * parameters are stored here
 * While none of them require size parameter to work, 
 * I still included it as a good practice.
 */

#include <stdio.h>
#include <stdlib.h>

void f_2D_dynamic_arr(int rows, int cols, int **arr)
{
	/*
	 * Printing values of 2D dynamic arr
	 * You can't pass it as ptr to rows, because 
	 * data types don't allign, at this point it's
	 * so obvious that I'm bored
	 */
	printf("f_2D_dynamic_arr()\n");
	printf("5th value of arr[1][1]: %d\n", arr[1][1]);
	
	// I know it won't apply to all values,
	// but I don't wanna to drag this experiment any further
	
	// Btw, funny thing: accidentally wrote *((*arr + 1) + 2) and got 0,
	// then figured out that this row is smwr on the heap and I went out of border,
	// and goy some junk. C is so cool ahah
	printf("6th value of [3][3] arr, *(*(arr + 1) + 2): %d\n", 
					 *(*(arr + 1) + 2));  
} 

void f_dyn2D_static_rows(int rows, int cols, int (*arr)[3])
{
	/*
	 * You still here?
	 */
	printf("f_dyn2D_static_rows\n");
	printf("5th value of arr[1][1]: %d\n", arr[1][1]);
	// Still works, we are not violating types, simply dereferncing
	printf("6th value of [3][3] arr, *(*(arr + 1) + 2): %d\n", 
					 *(*(arr + 1) + 2));  

}

void f_dyn2D_static_rows_asPtr_toINT(int rows, int cols, int *arr)
{
	/*
	 * We stored static 2D array in heap and now we can 
	 * pass to a function and traverse as 1D arr, making it more flexible
	 * irony is it's soo meaningless ahahHAHA what am I doing with my time...
	 */

	printf("f_dyn2D_static_rows_asPtr_toINT\n");
	// error: subscripted value is neither array nor pointer nor vector
	// as it should
	// printf("8th value of arr[1][1]: %d\n", arr[1][1]);
	printf("8th element *(arr + 7): %d\n", *(arr + 7));	

	// If I were to use for loop here, would need arr[i * cols + j]

	// Doesn't work as well, obviously
	// printf("6th value of [3][3] arr, *((*arr + 1) + 2)%d\n", 
	//				 *((*arr + 1) + 2));  

}
