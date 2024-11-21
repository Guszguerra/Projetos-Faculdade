//2. Maior de Dois Números: Escreva um programa que receba dois números inteiros e imprima o maior deles.

#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0;

    scanf("%d %d", &n1, &n2);

    if(n1>n2)
        printf("O %d e maior.", n1);
    else
        printf("O %d e maior.", n2);
    return 0;
}
