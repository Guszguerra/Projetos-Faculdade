//Nome do Aluno: Gustavo Bispo Guerra

/*Faça um programa em C que solicita três números inteiros do usuário, armazenar em um vetor, exibir a
soma dos valores do vetor. O programa deve chamar uma função para calcular a soma dos valores e
retornar este valor. Não se esqueça de declarar no início do programa o protótipo da(s) função(ões).*/

#include <stdio.h>

int somaVetor(int v[]);

int main(){

    int vetor[3], i=0;

    for(i=0;i<3;i++){
        printf("\nDigite o %d num: ", i+1);
        scanf("%d", &vetor[i]);
    }

    int resultado = somaVetor(vetor);

    printf("\n%d + %d + %d = %d.", vetor[0], vetor[1], vetor[2], resultado);
    return 0;
}

int somaVetor(int v[]){
    int tamanho = 3, i=0, soma=0;
    for(i=0;i<tamanho;i++){
        soma += v[i];
    }
    return soma;
}
