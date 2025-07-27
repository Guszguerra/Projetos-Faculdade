#include <stdio.h>

int main(){

    int i=0, valores[5], numero = 0, maior=0;

    for(i=0;i<5;i++){
        printf("\n Digite um valor entre 1 e 100: \n");
        scanf("%d", &numero);

        if(numero < 1)
            printf("\nInválido, digite um numero entre 1 e 100.\n");
        else if(numero > 100)
            printf("\nInválido, digite um numero entre 1 e 100.\n");
        else
            valores[i] = numero;
    }

    maior = valores[0]; //Inicializa com o primeiro valor valido

    for(i=1;i<5;i++){
        if(valores[i]>maior){ //se o valor da execução for maior q o numero anterior em maior
            maior = valores[i]; //o novo maior vai ser o numero da execução.
        }
    }

    printf("O maior numero e o: %d", maior);

}
