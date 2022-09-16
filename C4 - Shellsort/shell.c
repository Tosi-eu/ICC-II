#include <stdio.h>
void shell_sort(int *arr, int ARRAY_SIZE);
void print_array(int *arr, int ARRAY_SIZE);
int read_array(int *arr, int ARRAY_SIZE);

int main(){

  int size;
  scanf("%d", &size);
  int *arr = malloc(size*sizeof(int));

  read_array(arr, size);
  shell_sort(arr, size);
  print_array(arr, size);

  free(arr);
  return 0;
}

void shell_sort(int *arr, int ARRAY_SIZE){
  int gap = 1;

  while(gap < (ARRAY_SIZE / 3)){
    gap = 3*gap + 1;
  }

  while(gap > 0){
    for(int i = gap; i < ARRAY_SIZE; i++){
        int j = i;
        int aux = arr[i];
        while(j >= gap && aux < arr[j - gap]){
          arr[j] = arr[j - gap];
          j -= gap;
        }
        arr[j] = aux;
    }
    gap = (gap - 1) / 3;
  }
}

int read_array(int *arr, int ARRAY_SIZE){
    for(int i = 0; i < ARRAY_SIZE; i++){
       scanf("%d", &arr[i]);
  }
  return *arr;
}

void print_array(int *arr, int ARRAY_SIZE){
  for(int i = 0; i < ARRAY_SIZE; i++){
    printf("%d ", arr[i]);
  }
}