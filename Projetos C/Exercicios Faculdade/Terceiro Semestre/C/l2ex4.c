#include <stdio.h>

int somaArray(int array[]);

int main(){
    int array[] = {5, 4, 2, 9, 8, 32};
    int soma = somaArray(array);
    printf("A soma dos valores do array e: %d.", soma);
}

int somaArray(int a[]){
    int soma = 0, i = 0;
    for(i=0;i<6;i++){
        soma += a[i];
    }
    return soma;
}
