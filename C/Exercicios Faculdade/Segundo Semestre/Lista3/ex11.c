// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>

int menorNumero(int num1, int num2, int num3) {
    int menor = num1;
    if (num2 < menor) {
        menor = num2;
    }
    if (num3 < menor) {
        menor = num3;
    }
    return menor;
}

int main() {
    int num1, num2, num3;
    printf("Digite tr�s n�meros inteiros: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("O menor n�mero �: %d\n", menorNumero(num1, num2, num3));
    return 0;
}
