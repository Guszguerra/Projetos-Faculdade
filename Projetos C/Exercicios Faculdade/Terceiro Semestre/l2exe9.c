//Escreva um programa (não é necessário escrever uma função) que busca na seguinte matriz
//3x3 o maior inteiro:
//int m[3][3] ={{5,3,2}, {6,3,7}, {2,3,5}};

#include <stdio.h>

int main(){
    int m[3][3] = {{5,3,2}, {6,3,7}, {2,3,5}};
    int maior = m[0][0], i=0, j=0;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(m[i][j] > maior)
                maior = m[i][j];
        }
    }

    printf("O maior e : %d", maior);
}
