/*2.9. Leia o sal�rio de um trabalhador e o valor da presta��o de um empr�stimo. Se a presta��o for maior que 20% do
sal�rio imprima: Empr�stimo n�o concedido, caso contr�rio imprima: Empr�stimo concedido.*/

#include <stdio.h>

int main(){
    float sal = 0, prest = 0;

    printf("Digite o valor do seu salario e da prestacao em seguida: ");
    scanf("%f %f", &sal, &prest);

    if(prest > (sal /100) * 20)
        printf("Emprestimo nao concedido");
    else
        printf("Emprestimo concedido");
    return 0;
}
