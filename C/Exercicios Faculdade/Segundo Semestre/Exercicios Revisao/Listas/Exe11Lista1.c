//2.3. Leia um n�mero real. Se o n�mero for positivo imprima a raiz quadrada. Do contr�rio, imprima o n�mero ao quadrado.

#include <stdio.h>
#include <math.h>

int main(){

    float n = 0;
    scanf("%f", &n);
    if(n >=0){
        float raiz = sqrt(n);
        printf("A raiz de %.2f = %.2f.", n, raiz);
    }
    else{
        float quadrado = n*n;
        printf("O quadrado de %.2f = %.2f.", n, quadrado);
    }
    return 0;
}
