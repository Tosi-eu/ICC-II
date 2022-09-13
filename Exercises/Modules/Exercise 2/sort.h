#ifndef SORT_H
#define SORT_H
#define SERVICE_UNAVAILABLE 500

void merge_logic(int *array, int array1_start, int mid, int array2_start, int array2_end, int *aux_vet, int *comparisons, int *changes);
void merge(int *array, int array_start, int array_end, int *aux_vet, int *comparisons, int *changes);
void mergesort(int *array, int array_size);
void insertion_sort(int *arr, int array_size);
void free_matrix(int **matrix, int rows);

#endif