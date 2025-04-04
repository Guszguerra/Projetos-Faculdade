#include <stdio.h>

int retornaPrimeiro(int a[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Verificando elemento: %d\n", a[i]);  // Depuração

        if (a[i] % 2 == 0) {
            printf("Encontrado primeiro par: %d\n", a[i]);  // Depuração
            return a[i];
        }
    }
    return -1;
}

int main() {
    int array[] = {5, 4, 2, 9, 8, 32}, tamanho = 6;
    int res = retornaPrimeiro(array, tamanho);
    printf("O primeiro elemento par é: %d\n", res);
    return 0;
}
