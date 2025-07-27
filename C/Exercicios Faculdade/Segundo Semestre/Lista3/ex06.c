// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>

void somarEMedia(int vetor[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", (float)soma / tamanho);
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

    somarEMedia(vetor, tamanho);
    return 0;
}

