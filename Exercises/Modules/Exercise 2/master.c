#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

int main(){

    int Q, *N, **arrays_matrix; // respectivly: arrays amount, arrays size and matrix of arrays
    int *aux_array; //for mergesort

    scanf("%d", &Q);
    N = (int *) malloc(Q*sizeof(int));
    arrays_matrix = (int**) malloc(Q*sizeof(int*));

    if(N == NULL || arrays_matrix == NULL){
        return SERVICE_UNAVAILABLE;
    }

    for(int i = 0; i < Q; i++){
        scanf("%d", &N[i]);
    }

    for(int i = 0; i < Q; i++){
        arrays_matrix[i] = (int*)malloc(N[i]*sizeof(int));
        if(arrays_matrix[i] == NULL){
            return SERVICE_UNAVAILABLE;
        }
    }

    for(int i = 0; i < Q; i++){
        for(int j = 0; j < N[i]; j++){
            scanf("%d", &arrays_matrix[i][j]);
        }
    } 

    //### STARTING LOOP OF SORTING LOGIC ### //
    for(int i = 0; i < Q; i++){
        aux_array = (int *) malloc(N[i]*sizeof(int)); // aux array -> necessary for mergesort
        for(int j = 0; j < N[i]; j++){
            aux_array[j] = arrays_matrix[i][j];
        }

        insertion_sort(arrays_matrix[i], N[i]);
        mergesort(aux_array, N[i]);
        free(aux_array); // necessary to do here, else the arrays doesnt will be resetted (trust me)
    }

    free(N);
    free_matrix(arrays_matrix, Q);

  return 0;
}