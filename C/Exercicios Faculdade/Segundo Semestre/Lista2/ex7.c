//Nome do Aluno: Gustavo Bispo Guerra

/*Fa�a um programa em C que solicita tr�s n�meros inteiros do usu�rio, armazenar em um vetor, exibir a
soma dos valores do vetor. O programa deve chamar uma fun��o para calcular a soma dos valores e
retornar este valor. N�o se esque�a de declarar no in�cio do programa o prot�tipo da(s) fun��o(�es).*/

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
