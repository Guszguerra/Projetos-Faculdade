#include <stdio.h>

int main(){ //1.7. Leia um número inteiro e imprima o seu antecessor e o seu sucessor.
    int numero = 0, ant = 0, sus = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    ant = numero - 1;
    sus = numero + 1;

    printf("\nO numero e %d\nSeu antecessor: %d\nSeu sucessor: %d", numero, ant, sus);
}
