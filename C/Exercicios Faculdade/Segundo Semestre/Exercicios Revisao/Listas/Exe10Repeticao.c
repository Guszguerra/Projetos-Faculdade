/*. Leitura at� N�mero Igual: Leia n�meros do usu�rio at� que um n�mero igual ao anterior seja
inserido. Use um loop while.*/

#include <stdio.h>

int main(){

    int num = 0, num_Atual = -1;

    while(num!=num_Atual){
        num_Atual = num;
        printf("\nDigite um numero: \n");
        scanf("%d", &num);
    }
    printf("\n\nFinalizado(numeros iguais)");
    return 0;
}
