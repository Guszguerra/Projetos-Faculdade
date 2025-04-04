#include <stdio.h>

int main(){
    float n1 = 0, ai = 0, ap = 0, n2 = 0, nf = 0;
    printf("Digite nota n1: \n");
    scanf("%f", &n1);
    printf("Digite nota AI: \n");
    scanf("%f", &ai);
    printf("Digite nota AP: \n");
    scanf("%f", &ap);

    n2 = (ai+ap) / 2.0;
    nf = (n1+n2) / 2.0;

    if(nf >= 6)
        printf("passou com %f", nf);
    else{
        float n3 = 0.0;
        printf("Digite nota n3: \n");
        scanf("%f", &n3);
        if(n1>n2)
            n2 = n3;
        else
            n1 = n3;

        nf = (n1+n2)/2.0;

        if(nf >= 6)
            printf("Passou com %f", nf);
        else
            printf("Reprovou");
    }

}
