/*Salário com Desconto: Escreva um programa que receba o salário de um
funcionário e aplique um desconto de 10% se o salário for superior a R$ 2000.
Imprima o salário com o desconto aplicado, se houver.*/

#include <stdio.h>

int main(){
    float salario = 0;

    printf("Digite seu salario em R$: ");
    scanf("%f", &salario);

    if(salario > 2000){
        float descnt = (salario/100) * 10;
        salario -= descnt;
        printf("Seu salario com o desconto e: %.2f", salario);
    }


}
