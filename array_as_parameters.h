#ifndef ARRAY_AS_PARAMETERS_H
#define ARRAY_AS_PARAMETERS_H

// Initializers
void initialize_1D_arr(int size, int *arr);

void initialize_2D_arr(int rows_2Darr, int cols_2Darr, int *arr);

void initialize_2D_dynamic_arr(int rows_dyn2D, int cols_dyn2D, int **arr);

// Those are simple functions with a few printfs in them, not gonna explain them, check out methods

int oneDarr_asPtr_toINT(int size, int* p_1Darr_PtrInt); 

void oneDarr_asPtr_toWholeArr(int size_of_whole, int(*p_1Darr_PtrWhole)[3]);

void multiArr_asPtr_toINT(int* p_MultiArr_PtrToInt);

void multiArr_asPtr_toROW(int (*p_MultiArr_PtrToROW)[3]);

void multiArr_asPtr_toWhole(int (*p_MultiArr_PtrToWhole)[3][3]);

void f_dynamic1Darr(int size, int *p_dynamic_1Darr);

void f_dyn1D_as_row(int size, int (*p_dyn1D_as_row)[3]);

void f_2D_dynamic_arr(int rows, int cols, int **arr);

void f_dyn2D_static_rows(int rows, int cols, int (*arr)[3]);

void f_dyn2D_static_rows_asPtr_toINT(int rows, int cols, int *arr);

void f_stat_arr_of_ptrs_as_double_ptr(int size, int **arr);

void f_stat_arrOfPtr_as_row(int size, int (*arr)[3]);

#endif
