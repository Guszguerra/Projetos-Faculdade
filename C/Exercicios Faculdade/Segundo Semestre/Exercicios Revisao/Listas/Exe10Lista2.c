/*10. Verifica��o de Senha: Escreva um programa que solicite uma senha e verifique
se a senha � "senha123". Imprima "Senha correta" se for a senha certa e "Senha
incorreta" caso contr�rio.*/

#include <stdio.h>
#include <string.h>

int main(){
    char senha[21];
    char senhaCorreta[] = "senha123";

    printf("Digite sua senha: ");
    scanf("%20[^\n]%*c", senha);
    if(strcmp(senha, senhaCorreta)== 0)
        printf("Senha correta");
    else
        printf("Senha incorreta");
    return 0;
}
