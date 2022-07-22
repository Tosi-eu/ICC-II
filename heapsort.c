#include <stdio.h>
  
 //recursive function to swap items
  void swap(int *a, int *b);

  void heapify(int vet[], int n, int i);
  
  // main part of heap function
  void heapSort(int vet[], int n);
  
  // print function
  void printArray(int vet[], int n);

  
  // main
  int main() {

    int vet[5];

    for(int i = 0; i < 5; i++){
        scanf("%d", &vet[i]);

    }
  
    heapSort(vet, 5);
    printArray(vet, 5);

    return 0;
  }

    //recursive function to swap items
    void swap(int *a, int *b) {

      int aux = *a;
          *a = *b;
          *b = aux;

  }
  
  void heapify(int vet[], int n, int i) {
    // bigger, left and right terms
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && vet[left] > vet[largest])
      largest = left;
  
    if (right < n && vet[right] > vet[largest])
      largest = right;
  
    // if root isn't the largest, then continue
    if (largest != i) {
      swap(&vet[i], &vet[largest]);
      heapify(vet, n, largest);
    }
  }

    void heapSort(int vet[], int n) {
    // call heapify to buuild MAXHEAP (largest term as root)
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(vet, n, i);

    // heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&vet[0], &vet[i]);
  
      // last call to sort root terms, for getting the largest between themselves
      heapify(vet, i, 0);
    }
  }
  
    void printArray(int vet[], int n) {

    for (int i = 0; i < n; ++i){
      printf("%d ", vet[i]);
    }
    printf("\n");
    
  }