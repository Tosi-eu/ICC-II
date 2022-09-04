#include <stdio.h>
#define MAX 16

void insertion_sort(int *arr);
 
int main(){

 int i, arr[] = {1, 3, 2, 7, 5, 5, 2, 7, 2, 9, 3, 0, 8, 3, 1, 4};
 
 insertion_sort(arr);

 return 0;
}

void insertion_sort(int *arr){
  
 int j, aux, changes = 0, comparisons = 0;
  
  for(int i = 1; i < MAX; i++){
    changes++;
    aux = arr[i];
    for(j = i - 1; j >= 0; j--){
      comparisons++;
      if(arr[j] > aux){
         changes++;
         arr[j + 1] = arr[j];
      }else
        break;
    }
    changes++;
    arr[j + 1] = aux;
  }
  printf("I %d %d %d\n", MAX, changes, comparisons);
}

