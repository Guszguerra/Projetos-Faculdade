// Importar bibliotecas necessárias
import javax.swing.*;

// Classe que representa um botão no tabuleiro do jogo
public class BotaoDoJogo extends JButton {
    // Construtor para criar um botão com base na linha e coluna fornecidas
    public BotaoDoJogo(int linha, int coluna) {
        super();
    }

    // Método para verificar se o botão está vazio
    public boolean estaVazio() {
        return getText().isEmpty();
    }
}
