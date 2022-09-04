#include <stdio.h>
#define MAX 4

void swap(int *x, int *y);
void bubbleSort(int arr[], int ARRAY_SIZE);
void print_array(int *arr, int ARRAY_SIZE);

int main(){

  int *arr = malloc(MAX*sizeof(int));

  for(int i = 0; i < MAX; i++){
    scanf("%d", &arr[i]);
  }

  bubbleSort(arr, MAX);

  return 0;
}

void swap(int *x, int *y){
  int swap_terms = *x;
  *x = *y;
  *y = swap_terms;
}

void print_array(int arr[], int ARRAY_SIZE){

    for(int i = 0; i < ARRAY_SIZE; i++) {
      printf ("%d ", arr[i]);
  }
  printf ("\n");
}

void bubbleSort(int *arr, int ARRAY_SIZE){
  int sentinel, previous_modification;

  for (int i = 0; i < ARRAY_SIZE - 1; i++){
    sentinel = 0;
    for (int j = 0; j < ARRAY_SIZE - 1 - i; j++){
      if (arr[j] > arr[j + 1]){
        previous_modification = j + 1;
        printf("T %d %d\n", j, previous_modification);
        swap(&arr[j], &arr[j + 1]);
        sentinel = 1;
      }
    }
    // if sentinel doesn't exist after ending iteration, break
    if (!sentinel){
      break;
    }
  }
  print_array(arr, ARRAY_SIZE);
}