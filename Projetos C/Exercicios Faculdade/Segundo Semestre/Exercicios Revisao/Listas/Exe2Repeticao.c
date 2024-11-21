/*Números até um Valor: Solicite ao usuário um número e imprima todos os números de 1 até o
número inserido usando um loop for*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0, i = 0;

    scanf("%d", &n);
    system("cls");
    for(i=1;i<=n;i++){
        printf("%d\n", i);
    }
    return 0;
}
