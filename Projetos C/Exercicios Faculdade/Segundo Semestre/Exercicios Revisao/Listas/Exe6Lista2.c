// Verificação de Ano Bissexto: Escreva um programa que receba um ano e verifique se ele é um ano bissexto. Um ano é bissexto se for divisível por 4, mas não por 100, exceto se for divisível por 400.

#include <stdio.h>

int main(){

    int ano = 0;

    scanf("%d", &ano);
    if((ano%4==0)&&(ano%100!=0)|| (ano%400==0))
        printf("O ano e bissexto");
    else
        printf("O ano nao e bissexto");
    return 0;
}
