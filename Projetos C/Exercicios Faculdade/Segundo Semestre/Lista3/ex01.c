// Nome do aluno: Gustavo Bispo Guerra
#include <stdio.h>

// Função que permite ao usuário digitar todos os dados do vetor pessoas[]
void preencherPessoas(int n) {
    struct Pessoa {
        char nome[50];
        int idade;
    } pessoas[n];

    for (int i = 0; i < n; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
    }

    printf("\nDados das pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }
}

int main() {
    int n;
    printf("Digite o número de pessoas: ");
    scanf("%d", &n);
    preencherPessoas(n);
    return 0;
}
