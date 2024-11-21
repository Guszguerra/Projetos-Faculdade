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
                botoes[i][j] = new BotaoDoJogo(i, j);
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
                    // Se o jogador venceu, exibir uma mensagem e sair do jogo
                    JOptionPane.showMessageDialog(null, "Jogador venceu!");
                    System.exit(0);
                }
                // Se o jogador não venceu e todos os quadrados estão preenchidos, é um empate
                else if (jogadasFeitas == 9) {
                    JOptionPane.showMessageDialog(null, "Empate!");
                    System.exit(0);
                }
                // Se o jogador não venceu e ainda há quadrados vazios, é a vez do computador
                else {
                    // Fazer a jogada do computador
                    jogadaDoComputador();
                }
            }
        }
    }

    // Método para fazer a jogada do computador
    private void jogadaDoComputador() {
        // Criar uma nova instância de Random
        Random random = new Random();
        // Variáveis para armazenar a linha e coluna da jogada do computador
        int linha, coluna;
        // Loop até encontrar um quadrado vazio
        do {
            // Gerar índices de linha e coluna aleatórios
            linha = random.nextInt(3);
            coluna = random.nextInt(3);
        } while (!botoes[linha][coluna].estaVazio());
        // Definir o texto do botão na linha e coluna geradas como 'O'
        botoes[linha][coluna].setText("O");
        // Incrementar o número de jogadas feitas
        jogadasFeitas++;
        // Verificar se o computador venceu
        if (verificarVitoria('O')) {
            // Se o computador venceu, exibir uma mensagem e sair do jogo
            JOptionPane.showMessageDialog(null, "Computador venceu!");
            System.exit(0);
        }
        // Se o computador não venceu e todos os quadrados estão preenchidos, é um empate
        else if (jogadasFeitas == 9) {
            JOptionPane.showMessageDialog(null, "Empate!");
            System.exit(0);
        }
        // Se o computador não venceu e ainda há quadrados vazios, é a vez do jogador novamente
        else {
            // Alternar a vez
            vezDoJogador = true;
        }
    }

    // Método para verificar se um jogador venceu
    private boolean verificarVitoria(char jogador) {
        // Verificar as linhas e colunas para uma vitória
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
        // Verificar as diagonais para uma vitória
        if ((botoes[0][0].getText().equals(String.valueOf(jogador)) &&
                botoes[1][1].getText().equals(String.valueOf(jogador)) &&
                botoes[2][2].getText().equals(String.valueOf(jogador))) ||
                (botoes[0][2].getText().equals(String.valueOf(jogador)) &&
                        botoes[1][1].getText().equals(String.valueOf(jogador)) &&
                        botoes[2][0].getText().equals(String.valueOf(jogador)))) {
            return true;
        }
        // Se nenhuma vitória for encontrada, retornar falso
        return false;
    }
}
