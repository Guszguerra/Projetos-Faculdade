#include <stdio.h>
#include <stdlib.h>

//Explique o que acontece no seguinte c�digo e qual ser� sua sa�da:

int main(){
    int x = 10, y = 20, *p; //variavel x recebe 10, y 20 e � criado um ponteiro inteiro indentificado por p
    p = &x; //o ponteiro p aponta para o espa�o de mem�ria da variavel x
    *p = 30; //o espa�o de mem�ria para qual o ponteiro p aponta(variavel x) recebe valor 30
    p = &y; //ponteiro p come�a a apontar para o espa�o de memoria da variavel y
    *p = 40; //o espa�o de memoria para qual o ponteiro p aponta(var y) recebe valor 40
    printf("%d %d", x, y); //ser� impresso: 30 40

}
