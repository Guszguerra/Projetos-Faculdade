#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int aleatoriezando[20];
    int i=0;

    srand((time NULL));

    for(i=0;i<=20;i++){
        int numAle = rand() % 10;
        aleatoriezando[i] = numAle;
    }

    for(i=0;i<=20;i++){
        printf("%2d - %d \n", i, aleatoriezando[i]);
    }
    return 0;
}
