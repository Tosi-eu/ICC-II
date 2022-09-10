#include "funcs.h"

int main(){

  int ARRAY_SIZE;
  char method_name[8];

  setbuf(stdin, NULL); 
  scanf("%s", method_name);
  scanf("%d", &ARRAY_SIZE);

  int *arr = malloc(ARRAY_SIZE*sizeof(int));

  for(int i = 0; i < ARRAY_SIZE; i++){
      scanf("%d", &arr[i]);
  }

  choose_method(arr, method_name, ARRAY_SIZE);
  
  free(arr);

  return 0;
}