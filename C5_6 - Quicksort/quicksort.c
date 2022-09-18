#include <stdio.h>
#include <stdlib.h>

// function prototype
void quick_sort(int *arr, int start, int end);
 
//main
int main()
{
 int arr[7];
 
 // read 7 value from keyboard
 for(int i = 0; i < 7; i++){
  scanf("%d", &arr[i]);
 }
 
 //order values until (len(arr) - 1) --> 6
 quick_sort(arr, 0, 6);
 
 //print values in order ascendant
 for(int i = 0; i < 7; i++)
  printf("%d ", arr[i]);
 
 return 0;
}
 
//quick sort function
void quick_sort(int *arr, int start, int end) {
    int left, right, mid, aux;
     
    left = start;
    right = end;
    mid = arr[(start + end) / 2];
     
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