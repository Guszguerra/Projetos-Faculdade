#include <stdio.h>

int main(){ //2.1. Fa�a um programa que receba dois n�meros e mostre qual deles � o maior.

    int n1 = 0, n2 = 0;

    scanf("%d %d", &n1, &n2);
    if(n1 > n2)
        printf("O numero %d e maior", n1);
    else
        printf("O numero %d e maior", n2);
    return 0;
}
