#include <stdio.h>
#include <stdlib.h>

// function prototype
void quick_sort(int *a, int left, int right);
 
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
void quick_sort(int *vet, int left, int right) {
    int i, j, pivot, aux;
     
    i = left;
    j = right;
    pivot = vet[(left + right) / 2];
     
    while(i <= j) {
        while(vet[i] < pivot && i < right) {
            i++;
        }
        while(vet[j] > pivot && j > left) {
            j--;
        }
        if(i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(vet, left, j);
    }
    if(i < right) {
        quick_sort(vet, i, right);
    }
}