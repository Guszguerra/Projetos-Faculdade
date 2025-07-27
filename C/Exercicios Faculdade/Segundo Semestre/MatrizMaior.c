#include <stdio.h>

int main(){

    int numero = 0, valores[2][4], i=0, j=0, maior =0, algum=0;

    for(i=0;i<2;i++){
        for(j=0;j<4;j++){

            printf("\nDigite um valor entre 0 e 100: \n");
            scanf("%d", &numero);

            if(numero<0)
                printf("\nInvalido, digite um numero maior que 0.\n");
            else if(numero>100)
                printf("\nInvalido, digite um numero menor ou igual à 100.\n");
            else
                valores[i][j] = numero;
        }
    }

    maior = valores[0][0];
    algum = valores[1][2];

    for(i=1;i<2;i++){
        for(j=1;j<4;j++){
            if(valores[i][j]>maior){
                maior = valores[i][j];
            }
        }
    }

    printf("O maior numero na matriz e: %d\n\n", maior);

    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            printf(" %2d ", valores[i][j]);
        }
        printf("\n");
    }
}

