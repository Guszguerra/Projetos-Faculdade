//5. Média de Números: Calcule a média de 10 números fornecidos pelo usuário usando um loop for.

#include <stdio.h>

int main(){
    int i = 0;
    float nota = 0, soma = 0, media = 0;

    for(i=0;i<=9;i++){
        printf("Digite a nota n%d: ", i);
        scanf("%f", &nota);
        soma += nota;
    }
    media = soma / i;
    printf("\n\n\nA media e: %.2f", media);
}
