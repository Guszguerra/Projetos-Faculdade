// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>

void exibirImpares(int numero) {
    for (int i = 1; i <= numero; i++) {
        if (i % 2 != 0 && i % 7 != 0)
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    exibirImpares(numero);
    return 0;
}

