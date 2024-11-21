//Checagem de Idade: Escreva um programa que receba a idade de uma pessoa e imprima se ela é menor de idade (menos de 18 anos) ou maior de idade (18 anos ou mais).

#include <stdio.h>

int main(){

    int idade = 0;

    scanf("%d", &idade);
    if(idade <18)
        printf("Menor de idade.");
    else
        printf("Maior de idade.");
    return 0;
}
