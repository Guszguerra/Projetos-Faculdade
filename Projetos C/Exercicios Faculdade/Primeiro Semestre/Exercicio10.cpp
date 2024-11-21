#include <stdio.h>
#include <stdlib.h>

int main(){
  int dia, mes, ano;

  printf("Digite o dia, mes e ano. Ex: 10/02/2022.\n");
  scanf("%d %d %d", &dia, &mes, &ano);
  printf("Data digitada: %d\\%d\\%d.", dia, mes, ano);
}