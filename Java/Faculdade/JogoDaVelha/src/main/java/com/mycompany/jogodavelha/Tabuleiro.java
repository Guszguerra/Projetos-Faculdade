package com.mycompany.jogodavelha;

// Importar bibliotecas necessárias
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

// Classe que representa o tabuleiro do jogo
public class Tabuleiro extends JPanel {
    // Criar uma matriz 3x3 de instâncias de BotaoDoJogo
    private BotaoDoJogo[][] botoes = new BotaoDoJogo[3][3];
    // Variável para acompanhar de quem é a vez
    private boolean vezDoJogador = true; 
    // Variável para acompanhar o número de jogadas feitas
    private int jogadasFeitas = 0; 

    // Construtor da classe Tabuleiro
    public Tabuleiro() {
        // Definir o layout do painel como uma grade 3x3
        setLayout(new GridLayout(3, 3)); 
        // Criar uma nova instância de BotaoDoJogo para cada posição no tabuleiro
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j] = new BotaoDoJogo(i, j); // Instanciar botão
                // Adicionar um ActionListener a cada botão
                botoes[i][j].addActionListener(new OuvidorDeClique()); 
                // Adicionar o botão ao painel
                add(botoes[i][j]);
            }
        }
    }

    // Classe interna que representa um ouvinte de ações para os botões
    private class OuvidorDeClique implements ActionListener {
        // Método para lidar com cliques nos botões
        public void actionPerformed(ActionEvent e) {
            // Obter o botão que foi clicado
            BotaoDoJogo botao = (BotaoDoJogo) e.getSource(); 
            // Se o botão estiver vazio e for a vez do jogador
            if (botao.estaVazio() && vezDoJogador) { 
                // Definir o texto do botão como 'X'
                botao.setText("X"); 
                // Incrementar o número de jogadas feitas
                jogadasFeitas++; 
                // Verificar se o jogador venceu
                if (verificarVitoria('X')) {
                    // Se o jogador venceu, exibir uma mensagem e reiniciar o jogo
                    JOptionPane.showMessageDialog(null, "Jogador venceu!");
                    reiniciarJogo(); // Reinicia o jogo
                } else if (jogadasFeitas == 9) {
                    // Se empatar, exibir mensagem e reiniciar
                    JOptionPane.showMessageDialog(null, "Empate!");
                    reiniciarJogo();
                } else {
                    // Jogada do computador
                    vezDoJogador = false; // Indica que é a vez do computador
                    jogadaDoComputador();
                }
            }
        }
    }

    // Método para fazer a jogada do computador
    private void jogadaDoComputador() {
        Random random = new Random();
        int linha, coluna;

        do {
            linha = random.nextInt(3);
            coluna = random.nextInt(3);
        } while (!botoes[linha][coluna].estaVazio());

        // Colocar 'O' no botão escolhido
        botoes[linha][coluna].setText("O");
        jogadasFeitas++; 

        if (verificarVitoria('O')) {
            // Computador venceu
            JOptionPane.showMessageDialog(null, "Computador venceu!");
            reiniciarJogo();
        } else if (jogadasFeitas == 9) {
            // Empate
            JOptionPane.showMessageDialog(null, "Empate!");
            reiniciarJogo();
        } else {
            vezDoJogador = true; // Volta a ser a vez do jogador
        }
    }

    // Método para verificar se um jogador venceu
    private boolean verificarVitoria(char jogador) {
        // Verificar linhas e colunas
        for (int i = 0; i < 3; i++) {
            if (botoes[i][0].getText().equals(String.valueOf(jogador)) &&
                botoes[i][1].getText().equals(String.valueOf(jogador)) &&
                botoes[i][2].getText().equals(String.valueOf(jogador))) {
                return true;
            }
            if (botoes[0][i].getText().equals(String.valueOf(jogador)) &&
                botoes[1][i].getText().equals(String.valueOf(jogador)) &&
                botoes[2][i].getText().equals(String.valueOf(jogador))) {
                return true;
            }
        }
        // Verificar diagonais
        if (botoes[0][0].getText().equals(String.valueOf(jogador)) &&
            botoes[1][1].getText().equals(String.valueOf(jogador)) &&
            botoes[2][2].getText().equals(String.valueOf(jogador))) {
            return true;
        }
        if (botoes[0][2].getText().equals(String.valueOf(jogador)) &&
            botoes[1][1].getText().equals(String.valueOf(jogador)) &&
            botoes[2][0].getText().equals(String.valueOf(jogador))) {
            return true;
        }
        return false;
    }

    // Método para reiniciar o jogo
    private void reiniciarJogo() {
        // Limpar todos os botões e reiniciar contadores
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j].setText("");
            }
        }
        jogadasFeitas = 0;
        vezDoJogador = true;
    }
}
