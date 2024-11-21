#include <stdio.h>
#include <stdlib.h>

int main(){
  int num_01, num_02;

  printf("Digite dois numeros: ");
  scanf("%d %d", &num_01, &num_02);
  printf("%d\n%d", num_02, num_01);
  return 0;
}