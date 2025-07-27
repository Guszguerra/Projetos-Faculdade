/*2.8. Fa�a um programa que leia 2 notas de um aluno, verifique se as notas s�o v�lidas e exiba na tela a m�dia destas
notas. Uma nota v�lida deve ser, obrigatoriamente, um valor entre 0.0 e 10.0, onde caso a nota n�o possua um valor
v�lido, este fato deve ser informado ao usu�rio e o programa deve terminar imediatamente ap�s informar que uma
nota � inv�lida.*/

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
