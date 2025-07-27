#include <stdio.h>
#include <stdlib.h>

int main(){
  char caractere;
  int inteiro;
  float flutuante;

  printf("Digite um caractere, em seguida um valor inteiro e depois um flutuante:");
  scanf("%c %d %f", &caractere, &inteiro, &flutuante);
  printf("%c %d %f\n", caractere, inteiro, flutuante);
  printf("\t%c\t%d\t%f\n", caractere, inteiro, flutuante);
  printf("%c\n%d\n%f", caractere, inteiro, flutuante);
}