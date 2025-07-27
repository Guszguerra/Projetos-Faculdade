//Nota Aprovada ou Reprovada: Escreva um programa que receba uma nota de um aluno (entre 0 e 10). Se a nota for maior ou igual a 6, imprima "Aprovado". Caso contrário, imprima "Reprovado".

#include <stdio.h>

int main(){
    float nota = 0;

    scanf("%f", &nota);
    if((nota < 0)||(nota > 10))
        printf("Nota invalida.");
    else if(nota >= 6)
        printf("Aprovado.");
    else
        printf("Reprovado.");
    return 0;
}
