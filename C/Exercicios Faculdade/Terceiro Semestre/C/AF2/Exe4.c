#include <stdio.h>
#include <stdlib.h>
/*
Passagem de Ponteiros para Função
Implemente uma função que receba dois ponteiros para inteiros e troque os
valores entre eles sem retornar nada.*/

void trocavalores(int *ptr1, int *ptr2);

int main(){
    int x = 10, y = 5;

    printf("valores antigos: %d %d \n", x, y);

    trocavalores(&x, &y);

    printf("valores atualizados: %d %d \n", x, y);

}

void trocavalores(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
 }
