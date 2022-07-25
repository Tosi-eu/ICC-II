#include <stdio.h>
#include <stdlib.h>

//function prototypes
void mergesort(int *V, int size);
void sort(int *V, int *VetAux, int start, int end);
void merge(int *V, int *VetAux, int i, int m, int f);

int main () {

  int i;
  int v[8];

  for(i = 0; i < 8; i++){
    scanf("%d ", &v[i]);
  }
  mergesort(v, 8);

  for (i = 0; i < 8; i++) printf("%d ", v[i]);

  putchar('\n');

  return 0;
}

/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort(int *V, int size){

  int *aux = malloc(sizeof(int) * size);
  sort(V, aux, 0, size - 1);
  free(aux);

}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *V, int *VetAux, int start, int end) {
  if (start >= end){
    return;
  }

  int mid = (start + end) / 2;

  sort(V, VetAux, start, mid);
  sort(V, VetAux, (mid + 1), end);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (V[mid] <= V[mid + 1]){
    return;
  }

  merge(V, VetAux, start, mid, end);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *V, int *VetAux, int start, int mid, int end) {
  int temp, startAux = start, midAux = mid + 1;

  for (temp = start; temp <= end; temp++){
    VetAux[temp] = V[temp];
  }

  temp = start;

  while (startAux <= mid && midAux <= end) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (VetAux[startAux] <= VetAux[midAux]){
      V[temp++] = VetAux[startAux++];
    }else 
        V[temp++] = VetAux[midAux++];
  }

  while (startAux <= mid){
    V[temp++] = VetAux[startAux++];
  }

  while (midAux <= end){
    V[temp++] = VetAux[midAux++];
  }

}