#include <stdio.h>

int main() {
    int numero;
    printf("Digite um inteiro: ");
    scanf("%d", &numero);
    
    if (numero > 10 && numero % 2 == 0) {
        printf("1\n");
    } else if (numero % 2 != 0 || numero < 0) {
        printf("2\n");
    } else {
        printf("3\n");
    }
    
    return 0;
}