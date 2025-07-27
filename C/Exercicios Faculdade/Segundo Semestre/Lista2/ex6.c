//Nome do Aluno: Gustavo Bispo Guerra

#include <stdio.h>

int maiorMenor(int a, int b);

int main(){

    int num1=0, num2=0;

    printf("Digite os numeros para verificacao: ");
    scanf("%d %d", &num1, &num2);

    int resultado = maiorMenor(num1, num2);
    printf("\n%d e maior.", resultado);
    return 0;
}

int maiorMenor(int a, int b){
    int maior=0;

    if(a>b)
        maior = a;
    else
        maior = b;

    return maior;
}
