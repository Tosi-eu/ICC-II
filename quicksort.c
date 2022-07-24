#include <stdio.h>
#include <stdlib.h>

// function prototype
void quick_sort(int *vet, int start, int end);
 
//main
int main()
{
 int vet[7];
 
 // read 7 value from keyboard
 for(int i = 0; i < 7; i++){
  scanf("%d", &vet[i]);
 }
 
 //order values until (len(vet) - 1) --> 6
 quick_sort(vet, 0, 6);
 
 //print values in order ascendant
 for(int i = 0; i < 7; i++)
 {
  printf("%d ", vet[i]);
 }
 
 return 0;
}
 
//quick sort function
void quick_sort(int *vet, int start, int end) {
    int left, right, pivot, aux;
     
    left = start;
    right = end;
    pivot = vet[(start + end) / 2];
     
    while(left <= right) {
        while(vet[left] < pivot && left < end) {
            left++;
        }
        while(vet[right] > pivot && right > start) {
            right--;
        }
        if(left <= right) {
            aux = vet[left];
            vet[left] = vet[right];
            vet[right] = aux;
            left++;
            right--;
        }
    }
     
    if(right > start) {
        quick_sort(vet, start, right);
    }
    if(left < end) {
        quick_sort(vet, left, end);
    }
}