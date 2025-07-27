#include <stdio.h>

int main(){
  int a[] = {5, 4, 2, 9, 8, 32}, i = 0;
  int tamanho = sizeof(a) / sizeof(a[0]);

  for(i=0;i<tamanho;i++)
    printf("%d\n", a[i]);
}