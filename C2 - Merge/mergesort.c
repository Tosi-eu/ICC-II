#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int change = 0, compare = 0;

void merge_logic(int *array, int array1_start, int mid, int array2_start, int array2_end, int *aux_vet, int *comparisons, int *changes){
    int indexes_array1 = array1_start, indexes_array2 = array2_start, aux_array_indexes = 0;

    while (indexes_array1 <= mid && indexes_array2 <= array2_end){
        (*comparisons)++;
        (*changes)++;

        if(array[indexes_array1] <= array[indexes_array2]){
            aux_vet[aux_array_indexes] = array[indexes_array1];
            aux_array_indexes++;
            indexes_array1++;
        }else{
            if(!(array[indexes_array1] <= array[indexes_array2])){
              aux_vet[aux_array_indexes] = array[indexes_array2];
              aux_array_indexes++;
              indexes_array2++;
          }
       }
    }

    while(indexes_array1 <= mid){
        (*changes)++;

        aux_vet[aux_array_indexes] = array[indexes_array1];
        aux_array_indexes++;
        indexes_array1++;  
    }

    while(indexes_array2 <= array2_end){
        (*changes)++;

        aux_vet[aux_array_indexes] = array[indexes_array2];
        aux_array_indexes++;
        indexes_array2++;
    }

    aux_array_indexes = 0; //resetting variable at the final for join the splitted arrays
    for (int i = array1_start; i <= array2_end; i++, aux_array_indexes++){
        array[i] = aux_vet[aux_array_indexes];
        (*changes)++; //if necessary while merging array1 and array2
    }
}

void merge(int *array, int array_start, int array_end, int *aux_vet, int *comparisons, int *changes){

    int mid;
    if(array_start >= array_end){
        return;
    }else{
        mid = floor((array_start + array_end) / 2);   
        merge(array, array_start, mid, aux_vet, comparisons, changes); //start to mid -> first array
        merge(array, mid + 1, array_end, aux_vet, comparisons, changes); // mid + 1 to end -> second array
        merge_logic(array, array_start, mid, mid + 1, array_end, aux_vet, comparisons, changes); //group all and merge
    }
}

void mergesort(int *array, int array_size){
    int *aux_vet = (int *)malloc(array_size*sizeof(int));

    if(aux_vet == NULL){
        printf("Impossible to allocate memory...");
        return;
    }

    merge(array, 0, array_size - 1, aux_vet, &compare, &change);
    //printf("M %d %d %d", array_size, change, compare);

    free(aux_vet);
}

int main(){

  int vet[] = {1, 3, 2, 7, 5, 5, 2, 7, 2, 9, 3, 0, 8, 3, 1, 4};

  mergesort(vet, 16);

  return 0;
}