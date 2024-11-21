all: array_parameter

array_parameter: array_parameter.o oneD_arrays_handling.o multiD_arr_handling.o dynamic1D_arr_handling.o initializers.o dynamic2D_arr_handling.o static_arr_of_ptrs_handling.o
	gcc array_parameter.o oneD_arrays_handling.o multiD_arr_handling.o dynamic1D_arr_handling.o initializers.o dynamic2D_arr_handling.o static_arr_of_ptrs_handling.o -o array_parameter

array_parameter.o: array_parameter.c
	gcc -c array_parameter.c

oneD_arrays_handling.o : oneD_arrays_handling.c
	gcc -c oneD_arrays_handling.c

multiD_arr_handling.o: multiD_arr_handling.c
	gcc -c multiD_arr_handling.c
 
dynamic1D_arr_handling.o: dynamic1D_arr_handling.c
	gcc -c dynamic1D_arr_handling.c

dynamic2D_arr_handling.o: dynamic2D_arr_handling.c
	gcc -c dynamic2D_arr_handling.c

static_arr_of_ptrs_handling.o : static_arr_of_ptrs_handling.c
	gcc -c static_arr_of_ptrs_handling.c

initializers.o: initializers.c
	gcc -c initializers.c

clean:
	rm array_parameter.o oneD_arrays_handling.o multiD_arr_handling.o dynamic1D_arr_handling.o initializers.o array_parameter dynamic2D_arr_handling.o static_arr_of_ptrs_handling.o

