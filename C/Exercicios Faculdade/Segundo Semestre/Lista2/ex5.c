//Nome: Gustavo Bispo Guerra

/*
5. Fa�a um programa em C que solicita dois n�meros inteiros do usu�rio, calcula a soma desses n�meros
e exibe o resultado. O programa deve chamar uma fun��o para calcular a soma de dois n�meros
inteiros e retornar este valor. N�o se esque�a de declarar no in�cio do programa o prot�tipo da(s)
fun��o(�es).
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
