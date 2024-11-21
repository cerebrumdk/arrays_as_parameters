/*
 * Functions that take 1D arrays as parameters are stored here
 * While none of them require size parameter to work, 
 * I still included it as a good practice.
 */

#include <stdio.h>

int oneDarr_asPtr_toINT(int size, int* p_1Darr_PtrInt) 
{
	/*
	 * <p_1Darr_PtrInt> is a pointer to array's first element, 
	 * <p_1Darr_PtrInt[]> is the same thing
	 * <sizeof> on array function parameter ‘p_1Darr_PtrInt’ will return size of ‘int *’
	 * (<p_1Darr_PtrInt> doesn't see arr)
	 */
	printf("oneDarr_asPtr_toINT() changed second element, printed third one and returned size of parameter\n");
	printf("Third element of arr is %d\n", p_1Darr_PtrInt[2]);

	p_1Darr_PtrInt[2] = 4; // obviously, modifies arr

	// p_1Darr_PtrInt[>=SIZE] = digit; 
	// *** stack smashing detected ***: terminated
	// Aborted (core dumped)
	// So, don't fuck around with memory

	printf("Third element p_1Darr_PtrInt[2] %d\n", p_1Darr_PtrInt[2]);

	return sizeof(p_1Darr_PtrInt);
}

void oneDarr_asPtr_toWholeArr(int size_of_whole, int(*p_1Darr_PtrWhole)[3])
{
	/*
	 * <p_1Darr_PtrWhole> is a pointer to a row of 3 integers here
	 * Accepts only arrays of size 3, 
	 * it's in compiler-generated type information
	 */ 
	
	printf("oneDarr_asPtr_toWholeArr()\n");
	printf("Third element (*p_1Darr_PtrWhole)[2]: %d\n", (*p_1Darr_PtrWhole)[2]);
	printf("Second element *(*p_1Darr_PtrWhole + 1): %d\n\n", *(*p_1Darr_PtrWhole + 1));
}
