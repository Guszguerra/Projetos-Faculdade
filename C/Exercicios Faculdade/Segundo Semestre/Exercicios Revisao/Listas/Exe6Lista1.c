//1.6. Leia um valor em real e a cotação do dólar. Em seguida, imprima o valor correspondente em dólares

#include <stdio.h>

int main(){

    float real = 0, dolar = 0;

    printf("Digite um valor em reais: ");
    scanf("%f", &real);

    dolar = real / 5.59;

    printf("%.2f reais são convertidos para %.2f dolares.", real, dolar);
}


