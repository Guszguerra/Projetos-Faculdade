// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>

void encontrarMaior(int vetor[], int tamanho) {
    int maior = vetor[0];
    int posicao = 0;
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posicao = i;
        }
    }
    printf("Maior valor: %d, Posição: %d\n", maior, posicao);
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    encontrarMaior(vetor, tamanho);
    return 0;
}

