/*Soma dos Dígitos: Calcule a soma dos dígitos de um número inteiro fornecido pelo usuário usando
um loop for.*/

#include <stdio.h>

int main(){

    int num = 0,numMod = 0, i = 0, soma = 0; //Criando a variavel para guardar a soma.

    scanf("%d", &num);

    numMod = num;

    for(;numMod!=0;numMod /= 10){ //Não precisa de inicialização.  //Enquanto o numero for diferente de zero. //O número é dividido por dez a cada loop. (Serve para remover o ultimo digito a cada run).
        soma += numMod % 10; //Obtem o ultimo digito do numero e adiciona à noma.
    }

    printf("A soma dos digitos do numero %d = %d.", num, soma);
}
