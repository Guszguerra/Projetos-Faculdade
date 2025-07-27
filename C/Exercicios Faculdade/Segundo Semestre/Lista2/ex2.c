//Nome do aluno: Gustavo Bispo Guerra.

/*2. Fa�a um programa que calcule a m�dia aritm�tica de todas as turmas de uma escola.

Considere como entrada os n�meros de turmas
e
o n�mero de alunos de cada turma.

A m�dia aritm�tica de cada turma deve ser apresentada,
al�m de m�dia geral, que ser� o resultado da m�dia das turmas.

O programa dever� ter as fun��es mediaTurma e mediaEscola.

O usu�rio entrar�, dentro da fun��o main, com a
quantidade de turmas e, dentro da fun��o mediaEscola, com o n�mero de alunos de cada turma.*/

#include <stdio.h>

float mediaTurma(int alunos); //assinatura da funcao de media da turma, com o n de alunos como parametro
float mediaEscola(int qntdTurmas); //assinatura da funcao de media da escola, com n de turmas como parametro




int main(){
    int qntdTurmas = 0;
    printf("Digite a quantidade de turmas na escola: ");
    scanf("%d", &qntdTurmas); //Pegando a qntd de turmas da escola

    float mediaGeral = mediaEscola(qntdTurmas); //media geral da escola vai receber resultado da fun��o mediaEscola utilizando o n de turmas como parametro

    printf("Media geral da escola: %f", mediaGeral);

    return 0;
}

float mediaTurma(int alunos){
    int nota = 0, soma = 0, i =0;
    for(i=0; i < alunos; i++){
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%d", &nota); //guardando a nota do aluno(da vez da execu��o)
        soma += nota; //soma vai somar todas as notas
    }
    return soma / alunos; //media da turma vai ser retornada pela divis�o da soma das notas dos alunos pelo n de alunos.
}

float mediaEscola(int qntdTurmas){ //funcao de media da escola, utilizando quantidade de turmas como parametro

    int alunos = 0, i=0; //variavel pro n de alunos na turma
    float somaMedia = 0, media = 0;

    for(i=0;i < qntdTurmas; i++){
        printf("\nPor favor, digite o n de alunos na turma %d.", i + 1); //pede quantidade de alunos em tal turma, usando +1 pra n�o pegar 0 como indice.
        scanf("%d", &alunos);

        media = mediaTurma(alunos); //A media vai ser o resultado da funcao mediaTurma utilizando o n de alunos na turma como parametro.
        printf("Media da turma %d: %.2f\n", i+1, media); //exibindo a media da turma(da vez da execucao)

        somaMedia += media; //soma todas as medias de todas as turmas.
    }

    return somaMedia / qntdTurmas; //retorna como valor a media da escola toda(dividindo a soma da media de todas as turmas dividio pelo n de trumas)

}
