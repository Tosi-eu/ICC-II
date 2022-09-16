#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

void BubbleSort(int *arr, int ARRAY_SIZE){

  int previous_modification = ARRAY_SIZE;
  int array_end;

  for(int i = 0; i < ARRAY_SIZE; i++){
      array_end = previous_modification;
        for(int j = 0; j < array_end - 1; j++){
            //printf("C %d %d\n", j, j + 1);
            if(arr[j] > arr[j + 1]){
                previous_modification = j + 1;
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

void insertion_sort(int *arr, int ARRAY_SIZE){
  
 int j, aux; //changes = 0, comparisons = 0;
  
  for(int i = 1; i < ARRAY_SIZE; i++){
    //changes++;
    aux = arr[i];
    for(j = i - 1; j >= 0; j--){
     // comparisons++;
      if(arr[j] > aux){
        // changes++;
         arr[j + 1] = arr[j];
      }else
        break;
    }
   // changes++;
    arr[j + 1] = aux;
  }
  //printf("I %d %d %d\n", MAX, changes, comparisons);
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

//N*LOG(N)
//void merge_logic(int *array, int array1_start, int mid, int array2_start, int array2_end, int *aux_vet, int *comparisons, int *changes){
void merge_logic(int *array, int array1_start, int mid, int array2_start, int array2_end, int *aux_vet){
    int indexes_array1 = array1_start, indexes_array2 = array2_start, aux_array_indexes = 0;

    while (indexes_array1 <= mid && indexes_array2 <= array2_end){
        //(*comparisons)++;
        //(*changes)++;

        if(array[indexes_array1] <= array[indexes_array2]){
            aux_vet[aux_array_indexes++] = array[indexes_array1++];
        }else{
            if(!(array[indexes_array1] <= array[indexes_array2])){
              aux_vet[aux_array_indexes++] = array[indexes_array2++];
          }
       }
    }

    while(indexes_array1 <= mid){
        //(*changes)++;
        aux_vet[aux_array_indexes++] = array[indexes_array1++];
    }

    while(indexes_array2 <= array2_end){
        //(*changes)++;

        aux_vet[aux_array_indexes++] = array[indexes_array2++];
    }

    aux_array_indexes = 0; //resetting variable at the final for join the splitted arrays
    for (int i = array1_start; i <= array2_end; i++, aux_array_indexes++){
        array[i] = aux_vet[aux_array_indexes];
        //(*changes)++; //if necessary while merging array1 and array2
    }
}

//void merge(int *array, int array_start, int array_end, int *aux_vet, int *comparisons, int *changes){
void merge(int *array, int array_start, int array_end, int *aux_vet){

    int mid;
    if(array_start >= array_end){
        return;
    }else{
        mid = floor((array_start + array_end) / 2);
        /*   
        merge(array, array_start, mid, aux_vet, comparisons, changes); //start to mid -> first array
        merge(array, mid + 1, array_end, aux_vet, comparisons, changes); // mid + 1 to end -> second array
        merge_logic(array, array_start, mid, mid + 1, array_end, aux_vet, comparisons, changes); //group all and merge
        */
        merge(array, array_start, mid, aux_vet); //start to mid -> first array
        merge(array, mid + 1, array_end, aux_vet); // mid + 1 to end -> second array
        merge_logic(array, array_start, mid, mid + 1, array_end, aux_vet); //group all and merge
    }
}

void mergesort(int *array, int array_size){
    int *aux_vet = (int *)malloc(array_size*sizeof(int));

    if(aux_vet == NULL){
        printf("Impossible to allocate memory...");
        return;
    }

    //merge(array, 0, array_size - 1, aux_vet, &compare, &change);
    merge(array, 0, array_size - 1, aux_vet);
    //printf("M %d %d %d", array_size, change, compare);

    free(aux_vet);
}

void heapify(int *arr, int ARRAY_SIZE, int i){
    int father = i;
    int first_son = 2 * i + 1;
    int second_son = 2 * i + 2;
  
    if(first_son < ARRAY_SIZE && arr[first_son] > arr[father]){
      //printf("Father received first son value %d %d\n", father, first_son);
      father = first_son;
    }

    if(second_son < ARRAY_SIZE && arr[second_son] > arr[father]){
      //printf("Father received second son value %d %d\n", father, second_son);
      father = second_son;
    }
  
    // if root isn't the father, then continue
    if (father != i){
      //printf("Father isn't the biggest, it's necessary to change %d %d\n", i, father);
      swap(&arr[i], &arr[father]);
      heapify(arr, ARRAY_SIZE, father); //after swap, it's necessary to create heap again
    }
      //printf("Father is the biggest, just continue %d %d\n", i, father);
  }

void heapSort(int *arr, int ARRAY_SIZE){

    for (int i = ARRAY_SIZE / 2 - 1; i >= 0; i--)
      heapify(arr, ARRAY_SIZE, i);

    for(int i = ARRAY_SIZE - 1; i >= 0; i--){
      //printf("Sorting array by the indexes: 0 %d\n", i);
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0); //last call to sort root terms, for creating the heap again
    }
    //print_array(arr, ARRAY_SIZE);
  }

  //O(n^(3/2))
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
//AUX FUNCS
void swap(int *a, int *b) {
  int aux = *a;
     *a = *b;
     *b = aux;
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

