//2.7. Fa�a um programa que receba dois n�meros e mostre o maior. Se por acaso, os dois n�meros forem iguais, imprima a mensagem N�meros iguais.

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
