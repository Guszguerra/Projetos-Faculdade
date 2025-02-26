#include <stdio.h>

int main() {
    int numero;
    printf("Digite um inteiro: ");
    scanf("%d", &numero);
    
    if (numero < 42) {
        printf("menor\n");
    } else if (numero == 42) {
        printf("igual\n");
    } else {
        printf("maior\n");
    }
    
    return 0;
}