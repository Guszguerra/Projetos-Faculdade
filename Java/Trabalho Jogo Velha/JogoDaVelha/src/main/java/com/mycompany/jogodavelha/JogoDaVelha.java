package com.mycompany.jogodavelha;

import java.util.Random;

public class JogoDaVelha {
    private char[][] tabuleiro;
    private char jogadorAtual;
    private char computador;

    public JogoDaVelha() {
        tabuleiro = new char[3][3];
        reiniciaJogo();
        jogadorAtual = 'X';
        computador = 'O';
    }

    public char getComputador() {
        return computador;
    }

    public boolean realizaJogada(int linha, int coluna) {
        if (tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogadorAtual;
            return true;
        }
        return false;
    }

    public boolean jogadaDoComputador() {
        Random random = new Random();
        int linha, coluna;
        while (true) {
            linha = random.nextInt(3);
            coluna = random.nextInt(3);
            if (tabuleiro[linha][coluna] == ' ') {
                tabuleiro[linha][coluna] = computador;
                return true;
            }
        }
    }

    public boolean verificaVencedor(char simbolo) {
        for (int i = 0; i < 3; i++) {
            if ((tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo) ||
                (tabuleiro[0][i] == simbolo && tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo)) {
                return true;
            }
        }
        return (tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo) ||
               (tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo);
    }

    public boolean tabuleiroCheio() {
        for (char[] linha : tabuleiro) {
            for (char celula : linha) {
                if (celula == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    public void reiniciaJogo() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tabuleiro[i][j] = ' ';
            }
        }
        jogadorAtual = 'X';
    }

    public char getJogadorAtual() {
        return jogadorAtual;
    }

    public void trocaJogador() {
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    public char[][] getTabuleiro() {
        return tabuleiro;
    }

    // Novo método: converte o estado do tabuleiro em uma string
    public String estadoTabuleiroParaString() {
        StringBuilder estado = new StringBuilder();
        for (char[] linha : tabuleiro) {
            for (char celula : linha) {
                estado.append(celula == ' ' ? '-' : celula);
            }
        }
        return estado.toString();
    }
}