package com.mycompany.jogodavelha;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JogoDaVelhaGUI {
    private JFrame frame;
    private JButton[][] botoes = new JButton[3][3];
    private JogoDaVelha jogo = new JogoDaVelha();
    private boolean jogadorAtivo = true;
    private BancoDeDados bancoDeDados = new BancoDeDados();
    private JLabel scoreLabel;

    public JogoDaVelhaGUI() {
        criaGUI();
        atualizarPontuacao();
    }

    public void criaGUI() {
        frame = new JFrame("Jogo da Velha");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 450);
        frame.setLayout(new BorderLayout());

        JPanel tabuleiroPanel = new JPanel(new GridLayout(3, 3));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j] = new JButton(" ");
                botoes[i][j].setFont(new Font("Arial", Font.PLAIN, 60));
                final int linha = i;
                final int coluna = j;
                botoes[i][j].addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        if (botoes[linha][coluna].getText().equals(" ") && jogadorAtivo) {
                            if (jogo.realizaJogada(linha, coluna)) {
                                botoes[linha][coluna].setText(String.valueOf(jogo.getJogadorAtual()));
                                if (jogo.verificaVencedor(jogo.getJogadorAtual())) {
                                    JOptionPane.showMessageDialog(frame, "Você ganhou!");
                                    bancoDeDados.salvarPartida("Jogador", jogo.estadoTabuleiroParaString());
                                    atualizarPontuacao();
                                    reiniciaJogo();
                                } else if (jogo.tabuleiroCheio()) {
                                    JOptionPane.showMessageDialog(frame, "Empate!");
                                    bancoDeDados.salvarPartida("Empate", jogo.estadoTabuleiroParaString());
                                    reiniciaJogo();
                                } else {
                                    jogadorAtivo = false;
                                    jogadaDoComputador();
                                }
                            }
                        }
                    }
                });
                tabuleiroPanel.add(botoes[i][j]);
            }
        }

        scoreLabel = new JLabel("Jogador: 0 | Computador: 0");
        scoreLabel.setFont(new Font("Arial", Font.PLAIN, 18));
        scoreLabel.setHorizontalAlignment(SwingConstants.CENTER);

        frame.add(scoreLabel, BorderLayout.NORTH);
        frame.add(tabuleiroPanel, BorderLayout.CENTER);
        frame.setVisible(true);
    }

    private void jogadaDoComputador() {
        try {
            Thread.sleep(250);
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }

        if (jogo.jogadaDoComputador()) {
            atualizarTabuleiro();
            if (jogo.verificaVencedor(jogo.getComputador())) {
                JOptionPane.showMessageDialog(frame, "Computador ganhou!");
                bancoDeDados.salvarPartida("Computador", jogo.estadoTabuleiroParaString());
                atualizarPontuacao();
                reiniciaJogo();
            } else if (jogo.tabuleiroCheio()) {
                JOptionPane.showMessageDialog(frame, "Empate!");
                bancoDeDados.salvarPartida("Empate", jogo.estadoTabuleiroParaString());
                reiniciaJogo();
            }
        }
        jogadorAtivo = true;
    }

    private void atualizarTabuleiro() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                botoes[i][j].setText(String.valueOf(jogo.getTabuleiro()[i][j]));
            }
        }
    }

    // Método auxiliar para obter o estado atual do tabuleiro como string
    private String obterEstadoTabuleiro() {
        return jogo.estadoTabuleiroParaString();
    }

    private void reiniciaJogo() {
        jogo.reiniciaJogo();
        atualizarTabuleiro();
    }

    private void atualizarPontuacao() {
        // Exemplo para atualizar o scoreLabel
        // scoreLabel.setText("Jogador: " + pontuacaoJogador + " | Computador: " + pontuacaoComputador);
    }
}