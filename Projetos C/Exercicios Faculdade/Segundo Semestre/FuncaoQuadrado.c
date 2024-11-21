#include <stdio.h>

int calcula_quad(int num);

int main(){
    int n1 = 0;
    scanf("%d", &n1);

    int quad = calcula_quad(n1);
    printf("Quadrado de %d e %d", n1, quad);
}

int calcula_quad(int num){
    return num*num;
}

