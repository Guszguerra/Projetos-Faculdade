// 2.5. Fa�a um programa que receba um n�mero inteiro e verifique se este n�mero � par ou �mpar.

#include <stdio.h>

int main(){
    int n = 0;

    scanf("%d", &n);
    if(n%2==0)
        printf("O n e par.");
    else
        printf("O n e impar");
    return 0;
}
