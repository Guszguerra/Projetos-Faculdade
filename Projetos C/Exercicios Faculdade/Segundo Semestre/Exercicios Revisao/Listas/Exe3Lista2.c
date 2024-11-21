//Número Par ou Ímpar: Escreva um programa que receba um número inteiro e imprima se ele é par ou ímpar.

#include <stdio.h>

int main(){
    int n = 0;

    scanf("%d", &n);
    if(n%2==0)
        printf("O numero e par.");
    else
        printf("O numero e impar.");
    return 0;
}
