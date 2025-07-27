#include <stdio.h>

int main() {
    char nome[100];
    printf("Digite seu nome: ");
    scanf("%99s", nome); // Limita a leitura a 99 caracteres
    printf("ola, %s\n", nome);
    return 0;
}