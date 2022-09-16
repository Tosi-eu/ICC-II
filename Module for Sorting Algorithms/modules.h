#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef MODULES_H
#define MODULES_H

//QUADRATICS
void BubbleSort(int *arr, int ARRAY_SIZE);
void insertion_sort(int *arr, int ARRAY_SIZE);
void selection_sort(int *arr, int ARRAY_SIZE);

//N LOG N
/*
void merge_logic(int *array, int array1_start, int mid, int array2_start, int array2_end, int *aux_vet, int *comparisons, int *changes);
void merge_logic(int *array, int array1_start, int mid, int array2_start, int array2_end, int *aux_vet, int *comparisons, int *changes);
void merge(int *array, int array_start, int array_end, int *aux_vet, int *comparisons, int *changes);
*/

void merge_logic(int *array, int array1_start, int mid, int array2_start, int array2_end, int *aux_vet);
void merge_logic(int *array, int array1_start, int mid, int array2_start, int array2_end, int *aux_vet);
void merge(int *array, int array_start, int array_end, int *aux_vet);

void mergesort(int *array, int ARRAY_SIZE);
void heapify(int *arr, int ARRAY_SIZE, int i);
void heapSort(int *arr, int ARRAY_SIZE);

//O(n^(3/2))
void shell_sort(int *arr, int ARRAY_SIZE);

//AUX FUNCS
void swap(int *x, int *y);
void print_array(int *arr, int ARRAY_SIZE);
int read_array(int *arr, int ARRAY_SIZE);

#endif