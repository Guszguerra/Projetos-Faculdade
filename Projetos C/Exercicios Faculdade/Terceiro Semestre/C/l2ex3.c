#include <stdio.h>

int menor(int array[], int t);  // Declara��o da fun��o

int main(){
  int a[] = {5, 4, 2, 9, 8, 32};
  int tamanho = sizeof(a) / sizeof(a[0]);
  int res = menor(a, tamanho);

  printf("Menor elemento: %d\n", res);  // Adicionada quebra de linha
  return 0;  // Garantindo retorno no main
}

int menor(int array[], int t){
  int i;
  int menor = array[0];

  for(i = 1; i < t; i++){  // Come�a do �ndice 1, pois menor j� � array[0]
    if(array[i] < menor){
        menor = array[i];  // Corrigida a atribui��o
    }
  }

  return menor;  // Retorna o menor valor encontrado
}
