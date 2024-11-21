/*
 * Functions that take MultiD arrays as params are stored here
 * While none of them require size parameter to work, 
 * I still included it as a good practice.
 */

#include <stdio.h>

void multiArr_asPtr_toINT(int* p_MultiArr_PtrToInt)
{
	/*
	 * multiD array passed as a pointer to its first integer element
	 *
	 * !Now you can index multiD only as a 1D array!
	 * Because after passing it as a pointer, type information about
	 * arrays' boundaries were lost, hence you are left with 
	 * one contiguous block of memory.
	 */
	
	// printf("Eighth element: %d\n", p_MultiArr_PtrToInt[3][2]); 
	// error: subscripted value is neither array nor pointer nor vector
	printf("multiArr_asPtr_toINT()\n");
	printf("Eighth element through *(p_MultiArr_PtrToInt + 7): %d\n", 
					*(p_MultiArr_PtrToInt + 7));
	printf("Seventh element p_MultiArr_PtrToInt[6]: %d\n\n", p_MultiArr_PtrToInt[6]);	
}

void multiArr_asPtr_toROW(int (*p_MultiArr_PtrToROW)[3])
{
	/*
	 * multiD array passed as a pointer to its row
	 * 
	 * Can be indexed as 2D array,
	 * but restricted to work only with arrays of column size 3
	 */
	printf("multiArr_asPtr_toROW()\n");
	printf("Eighth element p_MultiArr_PtrToROW[2][1]: %d\n", p_MultiArr_PtrToROW[2][1]);
	printf("Seventh element *(*(p_MultiArr_PtrToROW + 2)): %d\n\n", 
				*(*(p_MultiArr_PtrToROW + 2)));
}

void multiArr_asPtr_toWhole(int (*p_MultiArr_PtrToWhole)[3][3])
{
	/*
	 * multiD array passed as a pointer to the whole array
	 * again we sacrifies flexibility to get that sweet 
	 * compiler-generated type information about our rows and columns
	 */
	printf("multiArr_asPtr_toWhole\n");
	printf("Eighth element (*p_MultiArr_PtrToWhole)[2][1]: %d\n", (*p_MultiArr_PtrToWhole)[2][1]);
	printf("Seventh element *(*(*p_MultiArr_PtrToWhole + 2)): %d\n\n", 
				*(*(*p_MultiArr_PtrToWhole + 2)));
}
