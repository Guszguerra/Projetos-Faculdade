#include <stdio.h>
#include <stdlib.h>

int main(){
  char carac_01, carac_02, carac_03;

  printf("Digite tres caracteres: ");
  scanf("%c %c %c", &carac_01, &carac_02, &carac_03);
  printf("\n%c\n%c\n%c", carac_01, carac_02, carac_03);
}