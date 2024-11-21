//2.2. Leia um número fornecido pelo usuário. Se esse número for positivo, calcule a raiz quadrada do número. Se o número for negativo, mostre uma mensagem dizendo que o número é inválido.

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
