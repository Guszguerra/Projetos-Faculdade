#include <stdio.h>

#define TAMANHO_PILHA 5

int main() {
    int pilha[TAMANHO_PILHA]; // Pilha estática
    int topo = -1; // Indica que a pilha está vazia
    int opcao, valor;

    do {
        // Menu com opções a serem completadas
        printf("\nMenu:\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Exibir Pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // Leitura da opção do menu

        switch (opcao) {
            case 1:
                // Lógica para empilhar
                if (topo < TAMANHO_PILHA - 1) {
                    // Digite um valor para empilhar
                    // Atualizar topo e pilha
                    printf("\nDigite o valor a ser add: ");
                    scanf("%d", &valor);
                    pilha[++topo] = valor; //aumentando o valor do topo pois estamos com valor novo e guardando ele nesse espaço novo
                } else {
                    printf("Pilha cheia!\n");
                }
                break;

            case 2:
                // Lógica para desempilhar
                if (topo >= 0) {
                    // Exibir valor desempilhado
                    // Atualizar topo
                        printf("Valor à ser desempilhado: %d", pilha[topo--]);
                } else {
                    printf("Pilha vazia!\n");
                }
                break;

            case 3:
                // Lógica para exibir a pilha
                if (topo >= 0) {

                    int i = 0;
                    // Imprimir os elementos da pilha
                    for(i=topo;i>=0;i--){
                        printf("%d\n", pilha[i]);
                    }
                } else {
                    printf("Pilha vazia!\n");
                }
                break;

            case 0:
                // Finalizar o programa
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
