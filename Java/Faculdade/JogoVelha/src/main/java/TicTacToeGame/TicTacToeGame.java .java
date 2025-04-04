// Importar bibliotecas necessárias
import javax.swing.*;
import java.awt.*;

// Classe principal para o jogo da velha
public class TicTacToeGame {
    // Criar um novo JFrame para a janela do jogo
    private JFrame frame;

    // Criar uma nova instância de GameBoard
    private GameBoard gameBoard;

    // Construtor da classe TicTacToeGame
    public TicTacToeGame() {
        // Criar um novo JFrame com um título
        frame = new JFrame("Jogo da Velha");
        // Definir a operação padrão de fechar para encerrar o aplicativo quando a janela for fechada
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Criar uma nova instância de GameBoard e adicionar ao frame
        gameBoard = new GameBoard();
        frame.add(gameBoard);
        // Definir o tamanho do frame para 300x300 pixels
        frame.setSize(300, 300);
        // Centralizar o frame na tela
        frame.setLocationRelativeTo(null);
        // Tornar o frame visível
        frame.setVisible(true);
    }

    // Método principal para iniciar o jogo
    public static void main(String[] args) {
        // Criar uma nova instância da classe TicTacToeGame
        new TicTacToeGame();
    }
}