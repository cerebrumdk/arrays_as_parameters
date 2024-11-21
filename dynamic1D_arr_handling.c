/*
 * Functions that take Dynamic arrays as
 * parameters are stored here
 * While none of them require size parameter to work, 
 * I still included it as a good practice.
 */


#include <stdio.h>
#include <stdlib.h>

void f_dynamic1Darr(int size, int *p_dynamic_1Darr)
{
	/*
	 * Printing values of 1D dynamical array (parameter is as usual)
	 */

	printf("f_dynamic1Darr()\n");
	printf("Second value p_dynamic_1Darr[1]: %d\n", p_dynamic_1Darr[1]);
	printf("Second value (*p_dynamic_1Darr + 1): %d\n\n", (*p_dynamic_1Darr + 1));

}

void f_dyn1D_as_row(int size, int (*p_dyn1D_as_row)[3])
{
	/*
	 * Trying to pass dynamic array as a row of 3 ints and not pointer
	 */
	printf("f_dyn1D_as_row()\n"); 
	printf("Is it printing second value of (*p_dyn1D_as_row)[1]? value: %d\n",(*p_dyn1D_as_row)[1]);
	printf("What about now? *(*p_dyn1D_as_row + 1): %d\n\n", *(*p_dyn1D_as_row + 1));
	// Need to be very careful here, it's basically static chunk of memory on the heap,
	// expanding p_dyn1D_as_row will lead to segmentation fault and UB. 
	printf("let's try p_dyn1D_as_row[0][1] = %d\nAhah, so much fun\n", p_dyn1D_as_row[0][1]);
}
