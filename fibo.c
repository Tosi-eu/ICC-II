#include <stdio.h>
#include <time.h>

void fibonacci(int INTERVAL_LIMIT);

int main() {

  int n;

  scanf("%d", &n);

  while(n <= 1) {
    printf("Numero de termos invalido\n");
    scanf("%d", &n);
  }

  fibonacci(n);
  
  return 0;
}

void fibonacci(int INTERVAL_LIMIT){

  int last = 1, penultimate = 1, cont = 2, sum = 0;

  printf("1 1 ");
  while(cont < INTERVAL_LIMIT) {
      sum = last + penultimate;
      sleep(1);
      printf("%d ", sum);
      last = penultimate;
      penultimate = sum;
      cont++;
    }
}