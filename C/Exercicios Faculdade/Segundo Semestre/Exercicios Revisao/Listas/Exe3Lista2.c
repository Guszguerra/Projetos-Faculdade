//N�mero Par ou �mpar: Escreva um programa que receba um n�mero inteiro e imprima se ele � par ou �mpar.

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
