// 2.5. Faça um programa que receba um número inteiro e verifique se este número é par ou ímpar.

#include <stdio.h>

int main(){
    int n = 0;

    scanf("%d", &n);
    if(n%2==0)
        printf("O n e par.");
    else
        printf("O n e impar");
    return 0;
}
