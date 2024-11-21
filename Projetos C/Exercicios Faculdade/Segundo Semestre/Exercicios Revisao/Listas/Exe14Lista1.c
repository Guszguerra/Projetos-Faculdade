//2.6. Escreva um programa que, dados dois números inteiros, mostre na tela o maior deles, assim como a diferença existente entre ambos.

#include <stdio.h>

int main(){
    int n1 = 0, n2 = 0;

    scanf("%d %d", &n1, &n2);

    if(n1 > n2){
        int dif = n1 - n2;
        printf("O maior numero e o %d, e a diferenca e de %d.", n1, dif);
    }
    else{
        int dif = n2 - n1;
        printf("O maior numero e o %d, e a diferenca e de %d.", n2, dif);
    }
    return 0;
}
