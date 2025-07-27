//8. Intervalo de Valores: Escreva um programa que receba um número inteiro e verifique se ele está no intervalo de 10 a 20 (inclusive). Imprima "Dentro do intervalo" se estiver, e "Fora do intervalo" caso contrário.

#include <stdio.h>

int main(){

    int n = 0;

    scanf("%d", &n);
    if((n>10)&&(n<20))
        printf("Dentro do intervalo.");
    else
        printf("Fora do intervalo.");
    return 0;
}
