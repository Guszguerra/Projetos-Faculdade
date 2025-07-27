#include <stdio.h>   // Biblioteca padr�o para entrada e sa�da
#include <stdlib.h>  // Biblioteca padr�o para aloca��o de mem�ria e outras fun��es
#include <ctype.h>   // Biblioteca para fun��es de manipula��o de caracteres

// Fun��o para comparar dois inteiros (usada na ordena��o da mediana)
int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); // Retorna a diferen�a entre os valores apontados
}

// Aplica o filtro da mediana em uma imagem representada como matriz
void filtro_mediana(int altura, int largura, int **imagem) {
    // Aloca uma c�pia da matriz para preservar os valores originais
    int **copia = (int **)malloc(altura * sizeof(int *));
    for (int i = 0; i < altura; i++)
        copia[i] = (int *)malloc(largura * sizeof(int));

    // Copia a imagem original para a matriz auxiliar
    for (int i = 0; i < altura; i++)
        for (int j = 0; j < largura; j++)
            copia[i][j] = imagem[i][j];

    // Percorre a matriz aplicando a mediana em uma janela 3x3
    for (int i = 1; i < altura - 1; i++) {
        for (int j = 1; j < largura - 1; j++) {
            int vetor[9], k = 0;

            // Coleta os valores da vizinhan�a 3x3
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    vetor[k++] = copia[i + di][j + dj];
                }
            }

            // Ordena os valores e atribui a mediana ao pixel central
            qsort(vetor, 9, sizeof(int), compara);
            imagem[i][j] = vetor[4]; // O elemento do meio � a mediana
        }
    }

    // Libera a mem�ria alocada para a c�pia
    for (int i = 0; i < altura; i++)
        free(copia[i]);
    free(copia);
}

// Fun��o para ler uma imagem PGM (Portable GrayMap)
int lerPGM(const char *nomeArquivo, int *altura, int *largura, int ***imagem) {
    FILE *arquivo = fopen(nomeArquivo, "rb"); // Abre o arquivo em modo bin�rio
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    char tipo[3];
    int maxValor;

    // L� o tipo do arquivo (P2 ou P5)
    fscanf(arquivo, "%2s", tipo);

    // Ignora coment�rios (linhas que come�am com '#')
    char c;
    while ((c = fgetc(arquivo)) == '#') {
        while (fgetc(arquivo) != '\n');
    }
    ungetc(c, arquivo); // Devolve o caractere para a stream

    // L� dimens�es da imagem e valor m�ximo
    fscanf(arquivo, "%d %d %d", largura, altura, &maxValor);
    fgetc(arquivo); // Consome a quebra de linha

    // Aloca mem�ria para a matriz de pixels
    *imagem = (int **)malloc(*altura * sizeof(int *));
    for (int i = 0; i < *altura; i++)
        (*imagem)[i] = (int *)malloc(*largura * sizeof(int));

    // Se o formato for ASCII (P2), l� diretamente os valores
    if (tipo[0] == 'P' && tipo[1] == '2') {
        for (int i = 0; i < *altura; i++)
            for (int j = 0; j < *largura; j++)
                fscanf(arquivo, "%d", &(*imagem)[i][j]);
    }
    // Se for bin�rio (P5), l� os bytes e converte para inteiro
    else if (tipo[0] == 'P' && tipo[1] == '5') {
        printf("Arquivo est� no formato bin�rio (P5), convertendo para P2...\n");
        for (int i = 0; i < *altura; i++)
            for (int j = 0; j < *largura; j++)
                (*imagem)[i][j] = fgetc(arquivo);
    }
    else {
        printf("Formato inv�lido! Apenas PGM ASCII (P2) ou bin�rio (P5) s�o suportados.\n");
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    return 1; // Retorna sucesso
}

// Fun��o para salvar uma imagem no formato PGM ASCII (P2)
void salvarPGM(const char *nomeArquivo, int altura, int largura, int **imagem) {
    FILE *arquivo = fopen(nomeArquivo, "w"); // Abre o arquivo para escrita
    if (!arquivo) {
        printf("Erro ao criar o arquivo %s\n", nomeArquivo);
        return;
    }

    // Escreve o cabe�alho do arquivo PGM
    fprintf(arquivo, "P2\n");
    fprintf(arquivo, "%d %d\n", largura, altura);
    fprintf(arquivo, "255\n"); // Valor m�ximo de intensidade

    // Escreve os pixels da imagem
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            fprintf(arquivo, "%d ", imagem[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

int main() {
    int **imagem;
    int largura, altura;
    const char *arquivoEntrada = "entrada.pgm";
    const char *arquivoSaida = "saida.pgm";

    // L� a imagem PGM e converte para P2 se necess�rio
    printf("Lendo a imagem PGM...\n");
    if (!lerPGM(arquivoEntrada, &altura, &largura, &imagem)) {
        printf("Erro ao ler a imagem.\n");
        return 1;
    }

    printf("Imagem carregada: %dx%d\n", largura, altura);
    printf("Aplicando filtro da mediana...\n");

    // Aplica o filtro da mediana na imagem
    filtro_mediana(altura, largura, imagem);

    // Salva a imagem processada em um novo arquivo
    salvarPGM(arquivoSaida, altura, largura, imagem);

    // Libera a mem�ria alocada para a imagem
    for (int i = 0; i < altura; i++)
        free(imagem[i]);
    free(imagem);

    printf("Imagem processada salva em: %s\n", arquivoSaida);
    return 0;
}
