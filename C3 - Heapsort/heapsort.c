#include <stdio.h>
  
//parts of heapsort
void heapify(int *arr, int ARRAY_SIZE, int i);
void heapSort(int *arr, int ARRAY_SIZE);
  
//auxiliar functions
void swap(int *a, int *b);
void printArray(int *arr, int ARRAY_SIZE);

int main(){

  int *arr = malloc(5*sizeof(int));

  for(int i = 0; i < 5; i++){
    scanf("%d", &arr[i]);
    }
  
  heapSort(arr, 5);

  free(arr);
  return 0;
}

void swap(int *a, int *b) {
  int aux = *a;
     *a = *b;
     *b = aux;
  }
  
void heapify(int *arr, int ARRAY_SIZE, int i){
    int father = i;
    int first_son = 2 * i + 1;
    int second_son = 2 * i + 2;
  
    if(first_son < ARRAY_SIZE && arr[first_son] > arr[father]){
      printf("Father received first son value %d %d\n", father, first_son);
      father = first_son;
    }

    if(second_son < ARRAY_SIZE && arr[second_son] > arr[father]){
      printf("Father received second son value %d %d\n", father, second_son);
      father = second_son;
    }
  
    // if root isn't the father, then continue
    if (father != i) {
      printf("Father isn't the biggest, it's necessary to change %d %d\n", i, father);
      swap(&arr[i], &arr[father]);
      heapify(arr, ARRAY_SIZE, father); //after swap, it's necessary to create heap again
    }else
        printf("Father is the biggest, just continue %d %d\n", i, father);
  }

void heapSort(int *arr, int ARRAY_SIZE){

    for (int i = ARRAY_SIZE / 2 - 1; i >= 0; i--)
      heapify(arr, ARRAY_SIZE, i);

    for(int i = ARRAY_SIZE - 1; i >= 0; i--){
      printf("Sorting array by the indexes: 0 %d\n", i);
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0); //last call to sort root terms, for creating the heap again
    }
    print_array(arr, ARRAY_SIZE);
  }
  
void print_array(int *arr, int ARRAY_SIZE) {

  for (int i = 0; i < ARRAY_SIZE; ++i){
      printf("%d ", *(arr + i));
    }
    printf("\n");
  }