// Escreva um programa (não é necessário escrever uma função) que armazena em um array de
// 3 elementos a soma de todos os elementos de cada coluna da seguinte matriz:
// int m[3][3] ={{5,3,2}, {6,3,7}, {2,3,5}};

#include <stdio.h>

int main(){

    int m[3][3] = {{5,3,2}, {6,3,7}, {2,3,5}};
    int soma[3] = {0, 0, 0} , i=0, j=0;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            soma[j] += m[i][j];
        }
    }

    for(i=0;i<3;i++){
        printf("%d\n", soma[i]);
    }


}
