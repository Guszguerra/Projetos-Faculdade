#include <stdio.h>

void funcao(int array[], int tamanho);

int main(){
  int a[] = {5, 4, 2, 9, 8, 32};
  int tamanho = sizeof(a) / sizeof(a[0]);

  funcao(a, tamanho);
}

void funcao(int array[], int t){
  int i = 0;
  for(i=0;i<t;i++)
    printf("%d\n", array[i]);
}