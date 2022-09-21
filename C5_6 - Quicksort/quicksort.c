#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype
void quick_sort(int *arr, int start, int end);
 
//main
int main(){

 int size;
 scanf("%d", &size);
 int *arr = malloc(size*sizeof(int));

 srand(time(NULL));
 
 for(int i = 0; i < size; i++){
  scanf("%d", &arr[i]);
 }
 
 //order values until (len(arr) - 1) --> 6
 quick_sort(arr, 0, size - 1);
 
 //print values in order ascendant
 for(int i = 0; i < size; i++)
  printf("%d ", arr[i]);
 
 free(arr);
 return 0;
}
 
//quick sort function
void quick_sort(int *arr, int start, int end) {
    int left, right, mid, aux;
     
    left = start;
    right = end;
    int randomIndex = rand() / (RAND_MAX / end + 1);
    mid = arr[randomIndex];
     
    while(left <= right) {
        while(arr[left] < mid && left < end) {
            left++;
        }
        while(arr[right] > mid && right > start) {
            right--;
        }
        if(left <= right) {
            aux = arr[left];
            arr[left] = arr[right];
            arr[right] = aux;
            left++;
            right--;
        }
    }
     
    if(right > start) {
        quick_sort(arr, start, right);
    }
    if(left < end) {
        quick_sort(arr, left, end);
    }
}
