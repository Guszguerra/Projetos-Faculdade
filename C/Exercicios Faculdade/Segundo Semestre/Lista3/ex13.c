// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>

float calcularMedia(int num1, int num2, int num3) {
    return (num1 + num2 + num3) / 3.0;
}

int main() {
    int num1, num2, num3;
    printf("Digite tr�s n�meros inteiros: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("A m�dia �: %.2f\n", calcularMedia(num1, num2, num3));
    return 0;
}
