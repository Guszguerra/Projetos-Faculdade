#include <stdio.h>

int main() {
    float a[] = {4, 5, 3, 7, 1, 9, 10, 2, 6, 8};
    int tamanho = sizeof(a) / sizeof(a[0]);

    // Dividindo cada elemento por 2
    for (int i = 0; i < tamanho; i++) {
        a[i] /= 2;
    }

    // Imprimindo os elementos com uma casa decimal
    printf("Elementos do array após divisão por 2:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%.1f\n", a[i]);
    }

    return 0;
}