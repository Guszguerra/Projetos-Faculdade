//Programa que receba o valor do sal�rio-base de um funcion�rio. Calcule e imprima o sal�rio total a receber, adicionando ao valor do sal�rio-base uma gratifica��o de 5%.

#include <stdio.h>

int main(){

    float salariob = 0, bonus = 0, salariot = 0;

    printf("Digite o valor do seu salario base: ");
    scanf("%f", &salariob);

    bonus = (5.0 / 100.0) * salariob;
    salariot = salariob + bonus;

    printf("\nO seu salario e R$%.2f\nO bonus e de R$%.2f\nO salario total e de: %.2f.", salariob, bonus, salariot);
}
