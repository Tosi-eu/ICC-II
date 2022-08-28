#include <stdio.h>

int soma_intervalo(int N, int M);

int main(){

  int N, M;

  scanf("%d %d", &N, &M);

  int res = soma_intervalo(N, M);

  printf("%d", res);

}

int soma_intervalo(int N, int M){

  int somador = 0;

  if(N < M){
      for(int i = N; i <= M; i++){
          somador += i;
  }
}else if(M < N){
        for(int i = M; i <= N; i++){
          somador += i;
  }
}

return somador;
}