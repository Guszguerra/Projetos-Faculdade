//3. Soma dos Números Pares: Calcule a soma dos números pares de 1 a 100 usando um loop for.

#include <stdio.h>

int main(){
    int i = 0;
    int soma = 0;

    for(i=1;i<=100;i++){
        if(i%2==0){
            soma += i;
        }
    }

    printf("Soma dos n pares de 1 a 100: %d.", soma);

}
