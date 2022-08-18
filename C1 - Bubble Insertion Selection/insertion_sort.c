#include <stdio.h>
#define MAX 10

void insertion_sort(int *arr);
void print_vet(int *arr, int VECTOR_SIZE);
 
int main(){

 int i, arr[MAX];
 
 for(i = 0; i < MAX; i++){
  scanf("%d", &arr[i]);
 }
 
 insertion_sort(arr);
 print_vet(arr, MAX);

 return 0;
}
 
void insertion_sort(int *arr)
{
 int j, aux;
  
  for(int i = 1; i < MAX; i++)
  {
    aux = arr[i];
    for(j = i - 1; j >= 0 && aux < arr[j]; j--){
       arr[j + 1] = arr[j];
    }
    arr[j + 1] = aux;
  }
}

void print_vet(int *arr, int VECTOR_SIZE){

    for(int i = 0; i < VECTOR_SIZE; i++) {
      printf ("%d ", *(arr + i));
  }
  printf ("\n");
}