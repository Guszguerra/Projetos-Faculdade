#include <stdio.h>

int main(){
    float n1 = 0, n2 = 0, n3 = 0, n4 = 0, media = 0;

    printf("Digite suas quatro notas em sequencia: ");
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

    media = (n1 + n2 + n3 + n4) / 4;

    printf("\nSuas notas: %.2f, %.2f, %.2f e %.2f", n1, n2, n3, n4);
    printf("\nSua media e: %.2f", media);
}
