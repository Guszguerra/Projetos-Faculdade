/*N�meros at� um Valor: Solicite ao usu�rio um n�mero e imprima todos os n�meros de 1 at� o
n�mero inserido usando um loop for*/

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
