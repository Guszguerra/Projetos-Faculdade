//2.2. Leia um n�mero fornecido pelo usu�rio. Se esse n�mero for positivo, calcule a raiz quadrada do n�mero. Se o n�mero for negativo, mostre uma mensagem dizendo que o n�mero � inv�lido.

#include <stdio.h>
#include <math.h>

int main(){
    int n = 0;

    scanf("%d", &n);
    if(n >= 0){
        int raiz = sqrt(n);
        printf("A raiz quadrada de %d = %d.", n, raiz);
    }
    else
        printf("O numero e invalido.");
    return 0;
}
