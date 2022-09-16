#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

//BubbleSort header
void BubbleSort(int *arr, int ARRAY_SIZE);

//Auxiliar functions headers
void swap(int *x, int *y);
void print_array(int *arr, int ARRAY_SIZE);

int main(){

  clock_t begin = clock();
  srand(time(NULL));
  int *arr = malloc(MAX*sizeof(int));

  for(int i = 0; i < MAX; i++){
    arr[i] = (rand() % 1000);
  }

  BubbleSort(arr, MAX);


  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
  printf("\n\n%.2lf\n", time_spent);

  free(arr);
  return 0;
}

void swap(int *x, int *y){
  int swap_terms = *x;
  *x = *y;
  *y = swap_terms;
}

void print_array(int *arr, int ARRAY_SIZE){

    for(int i = 0; i < ARRAY_SIZE; i++) {
      printf ("%d ", *(arr + i));
  }
  printf ("\n");
}

void BubbleSort(int *arr, int ARRAY_SIZE) {

  int previous_modification = ARRAY_SIZE;
  int array_end;

  for(int i = 0; i < ARRAY_SIZE; i++){
      array_end = previous_modification;
        for(int j = 0; j < array_end - 1; j++){
            //printf("C %d %d\n", j, j + 1);
            if(arr[j] > arr[j + 1]){
                //previous_modification = j + 1;
                //printf("T %d %d\n", j, previous_modification);
                swap(&arr[j], &arr[j + 1]);
            }
      }

        if(previous_modification == array_end){
          break;
          }//without this works either, but is a improvement but it avoids unnecessary comparisons
      }
    //print_array(arr, ARRAY_SIZE);
  }