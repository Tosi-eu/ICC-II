#include <stdio.h>
#define MAX 10

void print_vet(int *arr, int VECTOR_SIZE);
void selection_sort(int *arr, int VECTOR_SIZE);

int main () {

  int i, arr[MAX];
  
  for(int i = 0; i < MAX; i++){
    scanf("%d", &arr[i]);
  }

  selection_sort(arr, MAX);
  print_vet(arr, MAX);
  
}

void print_vet(int *arr, int VECTOR_SIZE){

    for(int i = 0; i < VECTOR_SIZE; i++) {
      printf ("%d ", *(arr + i));
  }
  printf ("\n");
}

void selection_sort (int *arr, int VECTOR_SIZE){

  int i, j, min, swapper;
  
  for (i = 0; i < (VECTOR_SIZE - 1); i++) {
    /* min = first number not sorted yet */
    min = i;
    for (j = i+1; j < VECTOR_SIZE; j++) {
      /* if number is lesser than the adjacent, swap them*/
      if (arr[j] < arr[min]) {
           min = j;
      }
    }
    /* if min are different of the last number not sorted, swap him */
    if (i != min) {
      swapper = arr[i];
      arr[i] = arr[min];
      arr[min] = swapper;
    }
  }
}