/*
 * Functions that take static array of pointers as params are stored here
 * While none of them require size parameter to work, 
 * I still included it as a good practice.
 */
#include <stdio.h>

void f_stat_arr_of_ptrs_as_double_ptr(int size, int **arr)
{
	/*
	 * Priniting values of static array as double pointer parameter
	 */

	 printf("f_stat_arr_of_ptrs_as_double_ptr()\n");
	 printf("6th value arr[1][2]: %d\n", arr[1][2]);
	 printf("8th value *(*(arr + 2) + 1): %d\n", *(*(arr + 2) + 1));
}

// Yeah, I can't figure out how to turn it into a row form
//void f_stat_arrOfPtr_as_row(int size, int (*arr)[3])
//{
//	/*
//	 * Priniting values of static array as row parameter
//	 */
//	
//	printf("f_stat_arrOfPtr_as_row\n");
//	printf("6th value arr[1][2]: %d\n", arr[1][2]);
//	printf("8th value *(*(arr + 3) + 1): %d\n", *(*(arr + 3) + 1));
//}

