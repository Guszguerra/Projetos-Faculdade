/*4. Adivinhação de Número: Peça ao usuário para adivinhar um número (por exemplo, 42) e continue
pedindo até que o usuário acerte o número. Use um loop while.*/

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
