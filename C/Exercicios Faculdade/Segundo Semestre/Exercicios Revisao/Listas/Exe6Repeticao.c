 /*Tabela de Multiplica��o: Exiba a tabela de multiplica��o de um n�mero fornecido pelo usu�rio
usando um loop for*/

#include <stdio.h>

int tabuada(int a, int b){
    return a * b;
}

int main(){
    int num=0, i = 0;

    printf("Digite o n para a tabuada: \n");
    scanf("%d", &num);

    for(i=0;i<=10;i++){
        printf("%d * %d = %d.\n", num, i, tabuada(num, i));
    }
    return 0;
}
