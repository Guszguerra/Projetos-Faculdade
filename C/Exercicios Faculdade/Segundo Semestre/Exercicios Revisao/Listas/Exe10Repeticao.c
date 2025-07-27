/*. Leitura até Número Igual: Leia números do usuário até que um número igual ao anterior seja
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
