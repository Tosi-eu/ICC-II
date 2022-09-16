#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

int main(){

  int size;
  scanf("%d", &size);
  int *arr = malloc(size*sizeof(int));

  //BubbleSort(arr, size);
  //insertion_sort(arr, size);
  //selection_sort(arr, size);
  //mergesort(arr, size);
  //heapSort(arr, size);
  //shell_sort(arr, size);
  print_array(arr, size);

  free(arr);
  return 0;
}