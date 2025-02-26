Filtro de Mediana em C para Imagens PGM

1. Introdução

O filtro de mediana é uma técnica amplamente utilizada no processamento de imagens para reduzir ruídos impulsivos, como o ruído "sal e pimenta" (caracterizado por pixels aleatórios extremamente claros ou escuros, simulando grãos de sal e pimenta espalhados pela imagem). Esse tipo de ruído ocorre frequentemente em imagens digitalizadas ou transmitidas por canais ruidosos. O principal objetivo do filtro de mediana é preservar as bordas da imagem enquanto remove ruídos indesejados, tornando-o ideal para aplicações em visão computacional e pré-processamento de imagens.

2. Funcionamento do Filtro de Mediana e Implementação

O filtro de mediana funciona substituindo cada pixel da imagem pelo valor mediano de seus pixels vizinhos dentro de uma janela deslizante (geralmente 3x3). Isso permite suavizar a imagem sem borrar detalhes como ocorre com filtros de média.

A implementação em C segue os seguintes passos:

Leitura da imagem PGM: O programa suporta imagens no formato P2 (ASCII) e P5 (binário), realizando a conversão para P2 quando necessário.

Criação de uma cópia da imagem: Mantém-se uma cópia da imagem original para evitar alterações durante a execução do filtro.

Aplicação do filtro de mediana:

Para cada pixel (exceto bordas), coletam-se os valores da vizinhança 3x3.

Os valores são ordenados e o pixel central é substituído pelo valor mediano.

Salvamento da imagem filtrada: O resultado é salvo em um novo arquivo PGM no formato P2.

3. Exemplos de Uso

Para executar o programa, salve uma imagem PGM chamada entrada.pgm no mesmo diretório do executável e execute o código. O programa processará a imagem e salvará o resultado em saida.pgm.

./filtro_mediana

Exemplo de Entrada:
Uma imagem PGM contendo ruído "sal e pimenta".

Exemplo de Saída:
A mesma imagem com ruído reduzido, preservando bordas e detalhes.

4. Desafios e Soluções

Durante o desenvolvimento, alguns desafios foram enfrentados:

Leitura de arquivos PGM em diferentes formatos: Foi necessário tratar arquivos P2 (ASCII) e P5 (binário), garantindo compatibilidade.

Otimização do código: A implementação do filtro de mediana envolve ordenação, e o uso de qsort ajudou a manter a simplicidade e eficiência do código.

Gerenciamento de memória: O uso de alocação dinâmica foi crucial para processar imagens de tamanhos variados sem desperdício de recursos.

Tempo de Execução em Imagens Grandes: O uso de uma abordagem ingênua, recalculando a mediana para cada pixel, pode tornar a execução lenta para imagens grandes. Implementações mais eficientes, como o uso de heaps ou histogramas deslizantes, podem reduzir a complexidade computacional.

Tratamento de Bordas: Como o filtro de mediana requer uma vizinhança de pixels, os pixels das bordas da imagem não possuem vizinhos suficientes para uma janela completa. Estratégias como replicação de bordas ou exclusão dessas regiões precisam ser consideradas.

Uso de Memória: A alocação dinâmica pode ser um desafio, especialmente ao lidar com imagens grandes. O uso excessivo de memória pode levar a problemas de fragmentação ou falha na alocação.

Precisão na Conversão P5 para P2: A conversão de imagens binárias (P5) para ASCII (P2) pode levar à perda de informações se não for feita corretamente, especialmente em imagens com níveis de cinza elevados.

5. Conclusão

O filtro de mediana implementado em C se mostrou eficaz na remoção de ruídos, preservando detalhes importantes da imagem. Ele pode ser adaptado para diferentes tamanhos de janelas e aplicado em diversos contextos de processamento de imagens. O projeto forneceu uma excelente oportunidade para explorar técnicas de manipulação de arquivos, alocação dinâmica de memória e algoritmos de ordenação.
