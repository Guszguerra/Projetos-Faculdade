/*Soma dos D�gitos: Calcule a soma dos d�gitos de um n�mero inteiro fornecido pelo usu�rio usando
um loop for.*/

#include <stdio.h>

int main(){

    int num = 0,numMod = 0, i = 0, soma = 0; //Criando a variavel para guardar a soma.

    scanf("%d", &num);

    numMod = num;

    for(;numMod!=0;numMod /= 10){ //N�o precisa de inicializa��o.  //Enquanto o numero for diferente de zero. //O n�mero � dividido por dez a cada loop. (Serve para remover o ultimo digito a cada run).
        soma += numMod % 10; //Obtem o ultimo digito do numero e adiciona � noma.
    }

    printf("A soma dos digitos do numero %d = %d.", num, soma);
}
