#include <stdio.h>

int main(){ //Leia um n�mero real e imprima o resultado do quadrado desse n�mero.

    float numero = 0;

    printf("Digite um numero: ");
    scanf("%f", &numero);

    float quadrado = numero*numero;

    printf("\nO quadrado de %.2f e %.2f.", numero, quadrado);
    return 0;
}
