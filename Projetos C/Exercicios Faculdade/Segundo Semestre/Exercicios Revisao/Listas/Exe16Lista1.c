/*2.8. Faça um programa que leia 2 notas de um aluno, verifique se as notas são válidas e exiba na tela a média destas
notas. Uma nota válida deve ser, obrigatoriamente, um valor entre 0.0 e 10.0, onde caso a nota não possua um valor
válido, este fato deve ser informado ao usuário e o programa deve terminar imediatamente após informar que uma
nota é inválida.*/

#include <stdio.h>

int main(){
    float n1 = 0, n2 = 0;

    printf("Primeira e segunda nota em sequencia: ");
    scanf("%f %f", &n1, &n2);

    if((n1<0.0)|| (n2 < 0.0) || (n1>10.0) || (n2>10.0)){
        printf("Nota invalida.");
    }
    else{
        float media = (n1 + n2) /2;
        printf("A media das suas notas e: %.2f", media);
    }
    return 0;
}
