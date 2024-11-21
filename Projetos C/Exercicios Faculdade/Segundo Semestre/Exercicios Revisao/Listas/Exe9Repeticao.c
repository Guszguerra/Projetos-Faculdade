/*
Leitura até Número Negativo: Leia números do usuário até que um número negativo seja inserido.
Use um loop while.
*/

#include <stdio.h>

int main(){

    int num = 0;

    while(num>=0){
        printf("\nDigite um novo numero: \n");
        scanf("%d", &num);
    }

    printf("\n\nFim(numero negativo inserido).");
    return 0;
}
