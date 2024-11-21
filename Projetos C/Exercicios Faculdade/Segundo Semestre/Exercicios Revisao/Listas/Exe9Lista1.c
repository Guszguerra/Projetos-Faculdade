#include <stdio.h>

int main(){ //2.1. Faça um programa que receba dois números e mostre qual deles é o maior.

    int n1 = 0, n2 = 0;

    scanf("%d %d", &n1, &n2);
    if(n1 > n2)
        printf("O numero %d e maior", n1);
    else
        printf("O numero %d e maior", n2);
    return 0;
}
