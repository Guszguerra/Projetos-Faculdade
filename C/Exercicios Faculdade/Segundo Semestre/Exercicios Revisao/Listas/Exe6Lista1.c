//1.6. Leia um valor em real e a cota��o do d�lar. Em seguida, imprima o valor correspondente em d�lares

#include <stdio.h>

int main(){

    float real = 0, dolar = 0;

    printf("Digite um valor em reais: ");
    scanf("%f", &real);

    dolar = real / 5.59;

    printf("%.2f reais s�o convertidos para %.2f dolares.", real, dolar);
}


