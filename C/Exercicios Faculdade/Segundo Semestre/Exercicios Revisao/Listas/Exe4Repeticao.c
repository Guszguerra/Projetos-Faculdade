/*4. Adivinha��o de N�mero: Pe�a ao usu�rio para adivinhar um n�mero (por exemplo, 42) e continue
pedindo at� que o usu�rio acerte o n�mero. Use um loop while.*/

#include <stdio.h>

int main(){
    int n = 0;

    printf("Chute um numero: ");
    scanf("%d", &n);

    while(n != 42){
        printf("Numero errado, tente outro: ");
        scanf("%d", &n);
    }
    printf("Numero correto.");
}
