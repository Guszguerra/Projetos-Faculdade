package com.mycompany.jogodavelhagui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JogoDaVelhaGUI {
    private JFrame frame; // Janela principal do jogo
    private JButton[][] botoes = new JButton[3][3]; // Botões que representam o tabuleiro
    private JogoDaVelha jogo = new JogoDaVelha(); // Instância do jogo
    private boolean jogadorAtivo = true; // Indica se o jogador está ativo
    private BancoDeDados bancoDeDados = new BancoDeDados(); // Instância do banco de dados
    private JLabel scoreLabel; // Label para exibir a pontuação

    // Construtor: cria a interface gráfica do jogo
    public JogoDaVelhaGUI() {
        criaGUI(); // Chama o método para criar a GUI
        atualizarPontuacao(); // Atualiza a pontuação
    }

    // Método para criar a interface gráfica
    public void criaGUI() {
        frame = new JFrame("Jogo da Velha"); // Cria a janela do jogo
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Fecha o programa ao fechar a janela
        frame.setSize(400, 450); // Define o tamanho da janela
        frame.setLayout(new BorderLayout()); // Define o layout da janela

        JPanel tabuleiroPanel = new JPanel(new GridLayout(3, 3)); // Painel para o tabuleiro

        // Criação dos botões do tabuleiro
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j] = new JButton(" "); // Botão vazio
                botoes[i][j].setFont(new Font("Arial", Font.PLAIN, 60)); // Define a fonte do botão
                final int linha = i; // Captura a linha
                final int coluna = j; // Captura a coluna
                botoes[i][j].addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        if (botoes[linha][coluna].getText().equals(" ") && jogadorAtivo) {
                            if (jogo.realizaJogada(linha, coluna)) { // Realiza a jogada
                                botoes[linha][coluna].setText(String.valueOf(jogo.getJogadorAtual())); // Atualiza o botão com o símbolo do jogador
                                if (jogo.verificaVencedor(jogo.getJogadorAtual())) {
                                    JOptionPane.showMessageDialog(frame, "Você ganhou!"); // Mensagem de vitória
                                    bancoDeDados.salvarPartida("Jogador", obterEstadoTabuleiro()); // Salva a partida no banco de dados
                                    atualizarPontuacao(); // Atualiza a pontuação
                                    reiniciaJogo(); // Reinicia o jogo
                                } else if (jogo.tabuleiroCheio()) {
                                    JOptionPane.showMessageDialog(frame, "Empate!"); // Mensagem de empate
                                    reiniciaJogo(); // Reinicia o jogo
                                } else {
                                    jogadorAtivo = false; // Alterna para o computador
                                    jogadaDoComputador(); // Jogada do computador
                                }
                            }
                        }
                    }
                });
                tabuleiroPanel.add(botoes[i][j]); // Adiciona o botão ao painel
            }
        }

        scoreLabel = new JLabel("Jogador: 0 | Computador: 0"); // Inicializa a label de pontuação
        scoreLabel.setFont(new Font("Arial", Font.PLAIN, 18)); // Define a fonte da label
        scoreLabel.setHorizontalAlignment(SwingConstants.CENTER); // Centraliza a label

        frame.add(scoreLabel, BorderLayout.NORTH); // Adiciona a label ao topo da janela
        frame.add(tabuleiroPanel, BorderLayout.CENTER); // Adiciona o painel do tabuleiro ao centro da janela
        frame.setVisible(true); // Torna a janela visível
    }

    // Método para realizar a jogada do computador
    private void jogadaDoComputador() {
        try {
            Thread.sleep(250); // Pausa para simular o tempo de resposta do computador
        } catch (InterruptedException ex) {
            ex.printStackTrace(); // Imprime a pilha de erros se ocorrer uma exceção
        }

        if (jogo.jogadaDoComputador()) { // Se o computador consegue jogar
            atualizarTabuleiro(); // Atualiza o tabuleiro na interface
            if (jogo.verificaVencedor(jogo.getComputador())) {
                JOptionPane.showMessageDialog(frame, "Computador ganhou!"); // Mensagem de derrota do jogador
                bancoDeDados.salvarPartida("Computador", obterEstadoTabuleiro()); // Salva a partida no banco de dados
                atualizarPontuacao(); // Atualiza a pontuação
                reiniciaJogo(); // Reinicia o jogo
            } else if (jogo.tabuleiroCheio()) {
                JOptionPane.showMessageDialog(frame, "Empate!"); // Mensagem de empate
                reiniciaJogo(); // Reinicia o jogo
            }
            jogadorAtivo = true; // Alterna para o jogador
        }
    }

    // Método para reiniciar o jogo
    private void reiniciaJogo() {
        jogo.reiniciaJogo(); // Reinicia o jogo
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j].setText(" "); // Limpa todos os botões
            }
        }
    }

    // Método para atualizar o tabuleiro na interface
    private void atualizarTabuleiro() {
        char[][] tabuleiro = jogo.getTabuleiro(); // Obtém o estado atual do tabuleiro
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j].setText(String.valueOf(tabuleiro[i][j])); // Atualiza o botão com o valor do tabuleiro
            }
        }
    }

    // Método para obter o estado do tabuleiro em formato de String
    private String obterEstadoTabuleiro() {
        StringBuilder sb = new StringBuilder();
        char[][] tabuleiro = jogo.getTabuleiro(); // Obtém o estado atual do tabuleiro
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sb.append(tabuleiro[i][j]); // Adiciona o valor ao StringBuilder
            }
            sb.append("\n"); // Adiciona uma nova linha após cada linha do tabuleiro
        }
        return sb.toString(); // Retorna a representação do tabuleiro
    }

    // Método para atualizar a pontuação
    private void atualizarPontuacao() {
        int[] pontuacoes = bancoDeDados.obterPontuacao(); // Obtém as pontuações do banco de dados
        scoreLabel.setText("Jogador: " + pontuacoes[0] + " | Computador: " + pontuacoes[1]); // Atualiza a label de pontuação
    }
}
