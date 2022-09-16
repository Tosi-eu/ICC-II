#include <stdio.h>
#define MAX 10

void print_array(int *arr, int ARRAY_SIZE);
void selection_sort(int *arr, int ARRAY_SIZE);
void swap(int *x, int *y);

int main (){

  int i, arr[MAX];
  
  for(int i = 0; i < MAX; i++){
    scanf("%d", &arr[i]);
  }

  selection_sort(arr, MAX);
  
}

void print_array(int *arr, int ARRAY_SIZE){

    for(int i = 0; i < ARRAY_SIZE; i++) {
      printf ("%d ", *(arr + i));
  }
  printf ("\n");
}

void swap(int *x, int *y){
  int swap_terms = *x;
  *x = *y;
  *y = swap_terms;
}

void selection_sort (int *arr, int ARRAY_SIZE){

  int i, subsequent_value, min;
  
  for (i = 0; i < (ARRAY_SIZE - 1); i++) {
    min = i; /* min = first number not sorted yet */
    for (subsequent_value = i + 1; subsequent_value < ARRAY_SIZE; subsequent_value++) {
      //printf("C %d %d\n", min, subsequent_value);
      if (arr[subsequent_value] < arr[min]) {
           min = subsequent_value; /* if number is lesser than the adjacent, the lesser turns into min*/
      }
    }
    if (i != min) { /* if min are different of the last number not sorted, swap him */
      //printf("T %d %d\n", i, min);
      swap(&arr[i], &arr[min]);
    }
  }
  //print_array(arr, ARRAY_SIZE);
}