 //1. N�mero Positivo ou Negativo: Escreva um programa que receba um n�mero inteiro e imprima se ele � positivo, negativo ou zero.

 #include <stdio.h>

 int main(){

    int n = 0;

    scanf("%d", &n);
    if(n == 0)
        printf("O numero e 0.");
    else if(n > 0)
        printf("O numero e positivo.");
    else
        printf("O numero e negativo.");
    return 0;
 }
