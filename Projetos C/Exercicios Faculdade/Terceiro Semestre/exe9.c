#include <stdio.h>

int main() {
    int N;
    printf("Digite um inteiro positivo N: ");
    scanf("%d", &N);
    
    if (N < 0) {
        printf("Por favor, digite um número inteiro positivo.\n");
        return 1; // Encerra o programa com erro
    }

    for (int i = N - 1; i >= 0; i--) {
        printf("%d\n", i);
    }
    
    return 0;
}