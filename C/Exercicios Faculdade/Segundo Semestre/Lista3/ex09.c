// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>

void multiplicarValores(int vetor[], int tamanho) {
    int produto = 1;
    for (int i = 0; i < tamanho; i++) {
        produto *= vetor[i];
    }
    printf("Resultado da multiplicação: %d\n", produto);
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

    multiplicarValores(vetor, tamanho);
    return 0;
}
