#include <stdio.h>
#include <stdlib.h>
//Implemente um programa que aloque dinamicamente memória para um vetor de
//n alunos e preencha os dados deles via entrada do usuário.
typedef struct {
    char nome[50];
    int idade;
    float nota;

} Alunos;

int main(){
    int n = 0, i = 0;

    printf("Digite o numero de alunos: \n");
    scanf("%d", &n);

    Alunos *ptr = (Alunos *)malloc(n * sizeof(Alunos));
    if(ptr == NULL){
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for(i=0;i<n;i++){
        printf("Digite os dados do aluno %d \n", i + 1);
        printf("Nome: ");
        scanf("%s", ptr[i].nome);
        printf("Idade: ");
        scanf("%d", &ptr[i].idade);
        printf("Nota: ");
        scanf("%f", &ptr[i].nota);
    }

    printf("Lista de alunos: \n");
    for(i=0;i<n;i++){
        printf("Aluno: %s, Idade: %d, Nota: %f", ptr[i].nome, ptr[i].idade, ptr[i].nota);
    }

    free(ptr);
}
