// Importar bibliotecas necessárias
import javax.swing.*;
import java.awt.*;

// Classe principal para o jogo da Velha
public class JogoDaVelha {
    // Criar um novo JFrame para a janela do jogo
    private JFrame janela;

    // Criar uma nova instância de Tabuleiro
    private Tabuleiro tabuleiro;

    // Construtor da classe JogoDaVelha
    public JogoDaVelha() {
        // Criar um novo JFrame com um título
        janela = new JFrame("Jogo da Velha");
        // Definir a operação padrão de fechamento para sair do aplicativo ao fechar a janela
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Criar uma nova instância de Tabuleiro e adicioná-la à janela
        tabuleiro = new Tabuleiro();
        janela.add(tabuleiro);
        // Definir o tamanho da janela para 300x300 pixels
        janela.setSize(300, 300);
        // Centralizar a janela na tela
        janela.setLocationRelativeTo(null);
        // Tornar a janela visível
        janela.setVisible(true);
    }

    // Método principal para iniciar o jogo
    public static void main(String[] args) {
        // Criar uma nova instância da classe JogoDaVelha
        new JogoDaVelha();
    }
}