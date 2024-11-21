//Nome: Gustavo Bispo Guerra

/*
5. Faça um programa em C que solicita dois números inteiros do usuário, calcula a soma desses números
e exibe o resultado. O programa deve chamar uma função para calcular a soma de dois números
inteiros e retornar este valor. Não se esqueça de declarar no início do programa o protótipo da(s)
função(ões).
*/

#include <stdio.h>

int soma(int a, int b);

int main(){

    int n1=0,n2=0;
    printf("Digite dois numeros interos para a soma: ");
    scanf("%d %d", &n1, &n2);

    int resultado = soma(n1, n2);

    printf("%d + %d = %d", n1, n2, resultado);
    return 0;
}

int soma(int a, int b){
    int valor=0;
    valor = a + b;
    return valor;
}
