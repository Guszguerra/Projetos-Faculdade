//Programa que receba o valor do salário-base de um funcionário. Calcule e imprima o salário total a receber, adicionando ao valor do salário-base uma gratificação de 5%.

#include <stdio.h>

int main(){

    float salariob = 0, bonus = 0, salariot = 0;

    printf("Digite o valor do seu salario base: ");
    scanf("%f", &salariob);

    bonus = (5.0 / 100.0) * salariob;
    salariot = salariob + bonus;

    printf("\nO seu salario e R$%.2f\nO bonus e de R$%.2f\nO salario total e de: %.2f.", salariob, bonus, salariot);
}
