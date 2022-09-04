#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 500 
/*
  30th group:

  - Guilherme Henrique Galdini Tosi
  - Gabriel de Souza Dalcim
  - Gabriel de Moraes Andreghetti
  - Paulo Henrique Vedovatto Turquetti
*/

//sorting methods (O(n^2)) headers
void bolha(int *array, int ARRAY_SIZE);
void selecao(int *array, int ARRAY_SIZE);
void choose_method(int *array, char method_name[], int ARRAY_SIZE);

int main(){

  int ARRAY_SIZE = 0;
  char method_name[8];

  scanf("%s", method_name);
  method_name[strcspn(method_name, "\n")] = 0; // returns all values ​​before '/n' -> it's like var--;

  scanf("%d", &ARRAY_SIZE);
  int *array = malloc(ARRAY_SIZE*sizeof(int));

  for(int i = 0; i < ARRAY_SIZE; i++){
      scanf("%d", &array[i]);
  }

  choose_method(array, method_name, ARRAY_SIZE);
  
  free(array);
  return 0;
}

void selecao(int *array, int ARRAY_SIZE){
  int lesser_value; //selection always considers the first value like the lesser value

  for(int i = 0; i < ARRAY_SIZE; i++){
      lesser_value = i;
      for(int subsequent_value = i + 1; subsequent_value < ARRAY_SIZE; subsequent_value++){
          printf("C %d %d\n", lesser_value, subsequent_value);
          if(array[lesser_value] > array[subsequent_value]){
              lesser_value = subsequent_value;
          }
      }
      if(lesser_value != i){
        printf("T %d %d\n", i, lesser_value);
        int aux = array[lesser_value];
                  array[lesser_value] = array[i];
                  array[i] = aux;
      }
  }

  for(int i = 0; i < ARRAY_SIZE; i++){
      printf("%d ", array[i]);
  }

}

void bolha(int *array, int ARRAY_SIZE) {

  int previous_modification = ARRAY_SIZE;
  int array_end;

  for(int i = 0; i < ARRAY_SIZE; i++){
      array_end = previous_modification;
        for(int j = 0; j < array_end - 1; j++){
            printf("C %d %d\n", j, j + 1);

            if(array[j] > array[j + 1]){
                previous_modification = j + 1;
                printf("T %d %d\n", j, previous_modification);
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
      }

        if(previous_modification == array_end){
          break;
          }//without this works either, but is a improvement but it avoids unnecessary comparisons
  }

  for(int i = 0; i < ARRAY_SIZE; i++){
      printf("%d ", array[i]);
  }
}

void choose_method(int *array, char method_name[8], int ARRAY_SIZE){

    if(strcmp(method_name, "bolha") == 0){
        bolha(array, ARRAY_SIZE);
    }else if(strcmp(method_name, "selecao") == 0){
        selecao(array, ARRAY_SIZE);
    }else{
        printf("method not found in directory...\n");
        exit(ERROR);
    }
}