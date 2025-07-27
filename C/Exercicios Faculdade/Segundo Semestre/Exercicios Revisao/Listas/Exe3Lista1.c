#include <stdio.h>

int main(){ //Digita tres n inteiros e imprime a soma

    int n1, n2, n3, soma;

    printf("Digite tres numeros em sequencia: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    printf("\n\nOs numeros sao: %d, %d e %d.\n", n1, n2, n3);

    soma = n1 + n2 + n3;
    printf("\nA soma e: %d.", soma);
}
