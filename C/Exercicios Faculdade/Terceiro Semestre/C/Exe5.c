int main(){
  int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    if (n < 42)
        printf("menor\n");
    else if (n == 42)
        printf("igual\n");
    else
        printf("maior\n");
}
