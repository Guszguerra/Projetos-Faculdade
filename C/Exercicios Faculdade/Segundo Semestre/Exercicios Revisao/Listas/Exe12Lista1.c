//2.4. Fa�a um programa que leia um n�mero e, caso ele seja positivo, calcule e mostre: 2.4.1 O n�mero digitado ao quadrado 2.4.2 A raiz quadrada do n�mero digitado

#include <stdio.h>
#include <math.h>

int main(){

    int n = 0;
    scanf("%d", &n);
    if(n >= 0){
        int quad = n*n , raiz = sqrt(n);
        printf("O numero digitado: %d\nQuadrado: %d\nRaiz: %d", n, quad, raiz);
    }
}
