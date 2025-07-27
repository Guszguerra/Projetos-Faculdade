//2.7. Faça um programa que receba dois números e mostre o maior. Se por acaso, os dois números forem iguais, imprima a mensagem Números iguais.

#include <stdio.h>

int main(){
    int n1, n2;

    scanf("%d %d", &n1, &n2);
    if(n1>n2)
        printf("O %d e maior.", n1);
    else if(n2>n1)
        printf("O %d e maior.", n2);
    else
        printf("Os numeros sao iguais");
    return 0;
}
