// Importar bibliotecas necessárias
import javax.swing.*;

// Classe que representa um botão no tabuleiro do jogo
public class BotaoDoJogo extends JButton {
    // Construtor para criar um botão
    public BotaoDoJogo(int linha, int coluna) {
        super(); // Chama o construtor da classe JButton
    }

    // Método para verificar se o botão está vazio
    public boolean estaVazio() {
        return getText().isEmpty(); // Verifica se o texto do botão está vazio
    }
}
