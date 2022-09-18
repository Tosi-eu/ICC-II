#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modules.h"

int main(){

  int size, op = -1;
  printf("Array size: ");
  scanf("%d", &size);
  int *array = malloc(size*sizeof(int));
  read_array(array, size);

  while(op != 0){

    int *aux_array = malloc(size*sizeof(int));

    for(int i = 0; i < size; i++)
      aux_array[i] = array[i];

    menu();
    scanf("%d", &op);
    clock_t begin = clock();

    switch (op){

    case 1:
      print_array(aux_array, size);
      bubblesort(aux_array, size);
      print_array(aux_array, size);

      clock_t end = clock();
      double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

      printf("\n\n%.2lf\n", time_spent);
      end = 0, begin = 0;
      free(aux_array);
      break;

    case 2:
      print_array(aux_array, size);
      insertion_sort(aux_array, size);
      print_array(aux_array, size);
      free(aux_array);
      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n\n%.2lf\n", time_spent);
      end = 0, begin = 0;
      break;

    case 3:
      print_array(aux_array, size);
      selection_sort(aux_array, size);
      print_array(aux_array, size);
      free(aux_array);

      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n\n%.2lf\n", time_spent);
      end = 0, begin = 0;
      break;

    case 4:
      print_array(aux_array, size);
      mergesort(aux_array, size);
      print_array(aux_array, size);

      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n\n%.2lf\n", time_spent);
      end = 0, begin = 0;

      free(aux_array);
      break;
    
    case 5:
      print_array(aux_array, size);
      heapsort(aux_array, size);
      print_array(aux_array, size);
      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n\n%.2lf\n", time_spent);

      end = 0, begin = 0;
      free(aux_array);
      break;

    case 6:
      print_array(aux_array, size);
      shell_sort(aux_array, size);
      print_array(aux_array, size);

      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n\n%.2lf\n", time_spent);
      end = 0, begin = 0;

      free(aux_array);
      break;

    case 7:
      print_array(aux_array, size);
      quick_sort(aux_array, 0, size);
      print_array(aux_array, size);

      end = clock();
      time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("\n\n%.2lf\n", time_spent);
      end = 0, begin = 0;

      free(aux_array);
      break;
    
    default:
      free(aux_array);
      break;
    }
  }

  free(array);
  return 0;
}