#include <stdio.h>
#include <stdlib.h>

#define QUICK 1
#define SHELL 0
#define NONE 2

typedef short int operatorType;

void shell(int *array, int arraySize, int *operations);
void quick(int * array, int start, int end, int *operations);
void swap(int *x, int *y);

int main()
{
  int arraySize, *mainArray, *auxArray, *auxArray2;
  int ShellCmp = 0, QuickCmp = 0;
  operatorType select;

  scanf("%d", &arraySize);

  if(arraySize <= 0){
    exit(EXIT_FAILURE);
  }else{
      mainArray = malloc(arraySize * sizeof(int));
      auxArray = malloc(arraySize * sizeof(int));
      auxArray2 = malloc(arraySize * sizeof(int));
  }

  for(int i = 0; i < arraySize; i++){

    if(scanf("%d", &mainArray[i]) == 0)
    {
      exit(EXIT_FAILURE);
    }
  }

  for(int i = 1; i <= arraySize; i++)
  {
    for(int j = 0; j < i; j++) {
      auxArray[j] = mainArray[j];
      auxArray2[j] = mainArray[j];
    }

    shell(auxArray, i, &ShellCmp);
    quick(auxArray2, 0, i - 1, &QuickCmp);

    if(QuickCmp < ShellCmp)
    {
      select = QUICK;
    } 
    else if(ShellCmp < QuickCmp)
    {
      select = SHELL;
    } 
    else
    {
      select = NONE;
    }

    switch(select)
    {
      case QUICK:
         printf("Q ");
         break;
      case SHELL:
          printf("S ");
          break;
      case NONE:
          printf("- ");
          break;
    }
  }
  free(auxArray);
  free(auxArray2);
  free(mainArray);

  return 0;
}

void shell(int *array, int arraySize, int *operations){
    int gap = 1, ops = 0;

    while(gap <= arraySize)
    {
        gap *= 2;
    }

    gap = gap / 2 - 1;

    while(gap > 0)
    {
          for (int i = gap; i < arraySize; i += gap)
            {
                int x = array[i];
                ops++;
                int j = i - gap;
                while(j >= 0 && array[j] > x)
                  {
                      ops++;
                      array[j + gap] = array[j];
                      ops++;
                      j -= gap;
                  }
                  if (j >= 0)
                  {
                    ops++;
                  }
                  array[j + gap] = x;
                  ops++;
            }
          gap /= 2;
    }
    *operations = ops;
}

void quick(int *array, int start, int end, int *operations){
  if (start >= end){
    return;
  }
  int mid = (start + end) / 2;
  int pivot = array[mid];

  (*operations)++;

  int right = start;
  int left = end;

  while (1)
  {
    while(array[right] < pivot)
    {
      (*operations)++;
      right++;
    }
    (*operations)++;
    
    while(array[left] > pivot){
      (*operations)++;
      left--; 
    }   
    (*operations)++;

    if (left <= right) break;

    swap(&array[right], &array[left]);

    (*operations) += 3;
    right++;
    left--;
  }
  quick(array, start, left, operations);
  quick(array, right + 1, end, operations);
}

void swap(int *x, int *y)
{
  int swap_terms = *x;
  *x = *y;
  *y = swap_terms;
}
