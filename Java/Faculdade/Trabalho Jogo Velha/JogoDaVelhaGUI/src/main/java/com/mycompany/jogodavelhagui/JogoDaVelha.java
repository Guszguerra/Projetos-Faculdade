package com.mycompany.jogodavelhagui;

import java.util.Random;

public class JogoDaVelha {
    private char[][] tabuleiro; // Matriz que representa o tabuleiro
    private char jogadorAtual;  // Símbolo do jogador atual (X ou O)
    private char computador;    // Símbolo do computador (O)

    // Construtor: inicializa o jogo e define o jogador e o computador
    public JogoDaVelha() {
        tabuleiro = new char[3][3];
        reiniciaJogo(); // Chama o método para reiniciar o jogo
        jogadorAtual = 'X'; // O jogador começa como 'X'
        computador = 'O'; // O computador é 'O'
    }

    // Método para obter o símbolo do computador
    public char getComputador() {
        return computador;
    }

    // Método para realizar a jogada do jogador
    public boolean realizaJogada(int linha, int coluna) {
        if (tabuleiro[linha][coluna] == ' ') { // Verifica se a célula está vazia
            tabuleiro[linha][coluna] = jogadorAtual; // Coloca o símbolo do jogador
            return true; // Jogada realizada com sucesso
        }
        return false; // Jogada inválida
    }

    // Método para realizar a jogada do computador
    public boolean jogadaDoComputador() {
        Random random = new Random();
        int linha, coluna;
        while (true) {
            linha = random.nextInt(3);  // Gera uma linha aleatória
            coluna = random.nextInt(3); // Gera uma coluna aleatória
            if (tabuleiro[linha][coluna] == ' ') { // Verifica se a célula está vazia
                tabuleiro[linha][coluna] = computador; // Coloca o símbolo do computador
                return true; // Jogada realizada com sucesso
            }
        }
    }

    // Método para verificar se um jogador venceu
    public boolean verificaVencedor(char simbolo) {
        for (int i = 0; i < 3; i++) {
            // Verifica linhas e colunas
            if ((tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo) || 
                (tabuleiro[0][i] == simbolo && tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo)) {
                return true; // Vencedor encontrado
            }
        }
        // Verifica as diagonais
        return (tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo) || 
               (tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo);
    }

    // Método para verificar se o tabuleiro está cheio
    public boolean tabuleiroCheio() {
        for (char[] linha : tabuleiro) {
            for (char celula : linha) {
                if (celula == ' ') { // Retorna falso se encontrar uma célula vazia
                    return false; // O tabuleiro não está cheio
                }
            }
        }
        return true; // O tabuleiro está cheio
    }

    // Método para reiniciar o jogo, limpando o tabuleiro
    public void reiniciaJogo() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tabuleiro[i][j] = ' '; // Define todas as células como vazias
            }
        }
        jogadorAtual = 'X'; // Reinicia o jogador atual para 'X'
    }

    // Método para obter o símbolo do jogador atual
    public char getJogadorAtual() {
        return jogadorAtual;
    }

    // Alterna o jogador atual entre 'X' e 'O'
    public void trocaJogador() {
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X'; // Troca entre jogadores
    }

    // Método para obter o estado do tabuleiro
    public char[][] getTabuleiro() {
        return tabuleiro;
    }
}
