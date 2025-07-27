#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Escreva um programa em C que defina uma struct chamada Aluno,
//contendo nome (char[50]), idade (int) e nota (float).
//Em seguida, crie um ponteiro para essa struct
//e use-o para atribuir valores e imprimir os dados do aluno.

typedef struct{
    char nome[50];
    int idade;
    float nota;
} Aluno;

int main(){
    Aluno *ptr;

    ptr = (Aluno *)malloc(sizeof(Aluno));

    if(ptr == NULL){
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    strcpy(ptr->nome, "Gus");
    ptr->idade = 18;
    ptr->nota = 6.3F;

    printf("Nome: %s\n", ptr->nome);
    printf("Idade: %d\n", ptr->idade);
    printf("Nota: %.2f\n", ptr->nota);

    free(ptr);

}
