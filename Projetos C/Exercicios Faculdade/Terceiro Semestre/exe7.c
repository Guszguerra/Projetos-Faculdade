#include <stdio.h>

int main() {
    float N1, AI, AP, N2, NF;
    printf("Digite N1, AI e AP: ");
    scanf("%f %f %f", &N1, &AI, &AP);
    
    N2 = (AI + AP) / 2;
    NF = (N1 + N2) / 2;
    
    if (NF >= 6) {
        printf("passou com NF: %.2f\n", NF);
    } else {
        float N3;
        printf("Digite N3: ");
        scanf("%f", &N3);
        
        // Substitui a menor nota entre N1 e N2
        if (N1 < N2) {
            NF = (N3 + N2) / 2;
        } else {
            NF = (N1 + N3) / 2;
        }
        
        if (NF >= 6) {
            printf("passou com NF: %.2f\n", NF);
        } else {
            printf("não passou com NF: %.2f\n", NF);
        }
    }
    
    return 0;
}