/*9. Calculadora Simples: Escreva um programa que receba dois números e uma
operação (soma, subtração, multiplicação ou divisão) e imprima o resultado da
operação escolhida.*/

int somar(int a, int b){
    return a + b;
}

int multiplicar(int a, int b){
    return a * b;
}

int subtrair(int a, int b){
    return a - b;
}

int dividir(int a, int b){
    return a / b;
}

#include <stdio.h>

int main(){

    int n1 = 0, n2 = 0;
    char operacao;
    int res = 0;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("\n\nDigite uma operacao:\n\n+\n-\n/\n*\n");
    scanf(" %c", &operacao);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);
    if(operacao == '+'){
        res = somar(n1, n2);
    }
    else if(operacao == '-'){
        res = subtrair(n1, n2);
    }
     if(operacao == '*'){
        res = multiplicar(n1, n2);
    }
     if(operacao == '/'){
        res = dividir(n1, n2);
    }

    printf("%d %c %d = %d.", n1, operacao, n2, res);
    return 0;
}
