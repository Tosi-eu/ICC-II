#include <stdio.h>
//#include "shell_module.h"
void shell_sort(int *arr, int ARRAY_SIZE);
void print_array(int *arr, int ARRAY_SIZE);

int main(){

  int size;
  scanf("%d", &size);
  int *arr = malloc(size*sizeof(int));

  shell_sort(arr, size);
  print_array(arr, size);

  free(arr);
  return 0;
}

void shell_sort(int *arr, int ARRAY_SIZE){
  int gap = ARRAY_SIZE / 2;

  while(gap > 1){
    gap /= 2;

    for(int i = gap; i < ARRAY_SIZE; i++){
        int j = i;
        int aux = arr[i];
        while(j >= gap && aux < arr[j - gap]){
          arr[j] = arr[j - gap];
          j -= gap;
        }
        arr[j] = aux;
    }
  }
}

void print_array(int *arr, int ARRAY_SIZE){
  for(int i = 0; i < ARRAY_SIZE; i++){
    printf("%d ", arr[i]);
  }
}