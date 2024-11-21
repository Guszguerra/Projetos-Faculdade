/*7. Maior Número: Encontre o maior número em uma lista de números fornecidos pelo usuário usando
um loop for.*/

#include <stdio.h>

int main(){
    int i = 0;
    int lista[10]; //criando lista com 10 posições(de 0 até 9)

    for(i;i<10;i++)    //inicializando a variável.
        lista[i] = 0; //todos as posições com valor 0

    for(i=0;i<=9;i++){
        printf("\nDigite o %dn: \n", i + 1);
        scanf("%d", &lista[i]);
    }

    int maior = lista[0]; //Inicializa maior com o primeiro valor da lista
    for(i=1;i<10;i++){ //O loop começa com 1 pq ja usamos o lista[0] para iniciar a var, entao começamos a verificar a partir do segundo elemento
        if(lista[i] > maior){ //Se o valor atual na lista for maior que o valor ja armazenado em maior
            maior = lista[i]; //O novo maior numero será armazenado(atualiza maior se achar um numero maior)
        }
    }
    printf("\n\nO maior numero da lista e: %d", maior);
}
