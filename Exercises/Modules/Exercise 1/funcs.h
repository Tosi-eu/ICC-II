#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FUNCS_H
#define FUNCS_H
#define SERVICE_UNAVAILABLE 500 

//sorting methods (O(n^2)) headers
void bolha(int *arr, int ARRAY_SIZE);
void selecao(int *arr, int ARRAY_SIZE);

//auxiliar functions
void choose_method(int *arr, char method_name[8], int ARRAY_SIZE);
void swap(int *x, int *y);
void print_array(int *arr, int ARRAY_SIZE);

#endif