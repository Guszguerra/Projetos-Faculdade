#include <stdio.h>

int main() {
    float largura, altura;
    printf("Digite a largura e a altura do retângulo: ");
    scanf("%f %f", &largura, &altura);
    printf("A área do retângulo é: %.2f\n", largura * altura);
    return 0;
}