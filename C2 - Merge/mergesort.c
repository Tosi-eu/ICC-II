#include <stdio.h>
#include <stdlib.h>

void mergesort(int *ARRAY, int ARRAY_SIZE);
void sort(int *ORIGINAL_ARRAY, int *ARRAY_AUX, int START_INDEX_ARRAY, int END_INDEX_ARRAY);
void merge(int *ORIGINAL_ARRAY, int *ARRAY_AUX, int START_INDEX_ARRAY, int MID, int END_INDEX_ARRAY);

int main () {

  int v[8];

  for(int i = 0; i < 8; i++){
    scanf("%d ", &v[i]);
  }

  mergesort(v, 8);

  for(int i = 0; i < 8; i++){
      printf("%d ", v[i]);
  }

  return 0;
}

void mergesort(int *ARRAY, int ARRAY_SIZE){

  int *aux = malloc(sizeof(int) * ARRAY_SIZE);
  sort(ARRAY, aux, 0, ARRAY_SIZE - 1);
  free(aux);

}


void merge(int *ORIGINAL_ARRAY, int *ARRAY_AUX, int START_ARRAY_INDEX, int MID, int END_ARRAY_INDEX) {
  int temp_index, START_INDEX_AUX = START_ARRAY_INDEX, MID_INDEX_AUX = MID + 1;

  for(temp_index = START_ARRAY_INDEX; temp_index <= END_ARRAY_INDEX; temp_index++){
    ARRAY_AUX[temp_index] = ORIGINAL_ARRAY[temp_index];
  }

  temp_index = START_ARRAY_INDEX;
  while (START_INDEX_AUX <= MID && MID_INDEX_AUX <= END_ARRAY_INDEX) {
    if (ARRAY_AUX[START_INDEX_AUX] <= ARRAY_AUX[MID_INDEX_AUX]){
        ORIGINAL_ARRAY[temp_index++] = ARRAY_AUX[START_INDEX_AUX++];
    }else 
        ORIGINAL_ARRAY[temp_index++] = ARRAY_AUX[MID_INDEX_AUX++];
  }

  while (START_INDEX_AUX <= MID){
    ORIGINAL_ARRAY[temp_index++] = ARRAY_AUX[START_INDEX_AUX++];
  }

  while (MID_INDEX_AUX <= END_ARRAY_INDEX){
    ORIGINAL_ARRAY[temp_index++] = ARRAY_AUX[MID_INDEX_AUX++];
  }

}

void sort(int *ORIGINAL_ARRAY, int *ARRAY_AUX, int START_INDEX_ARRAY, int END_INDEX_ARRAY) {

  if (START_INDEX_ARRAY >= END_INDEX_ARRAY){
    return;
  }

  int mid = (START_INDEX_ARRAY + END_INDEX_ARRAY) / 2;

  sort(ORIGINAL_ARRAY, ARRAY_AUX, START_INDEX_ARRAY, mid); // sorting start to mid
  sort(ORIGINAL_ARRAY, ARRAY_AUX, (mid + 1), END_INDEX_ARRAY); //sorting mid + 1 to end

  if (ORIGINAL_ARRAY[mid] <= ORIGINAL_ARRAY[mid + 1]){ //if array[mid + 1] is lesser than that the previous index, is sorted yet, so break
    return;
  }

  merge(ORIGINAL_ARRAY, ARRAY_AUX, START_INDEX_ARRAY, mid, END_INDEX_ARRAY); // at the final, merge all of them
}