package com.mycompany.jogodavelhagui;

import java.sql.*;

public class BancoDeDados {
    private Connection connection; // Conexão com o banco de dados

    // Construtor: inicializa a conexão com o banco de dados
    public BancoDeDados() {
        try {
            connection = DriverManager.getConnection("jdbc:mysql://localhost/jogovelha", "root", "Mitaka73289135."); // Substitua 'usuario' e 'senha' pelos seus dados
        } catch (SQLException e) {
            e.printStackTrace(); // Imprime a pilha de erros se ocorrer uma exceção
        }
    }

    // Método para salvar uma partida no banco de dados
    public void salvarPartida(String vencedor, String tabuleiro) {
        String sql = "INSERT INTO partidas (vencedor, tabuleiro) VALUES (?, ?)"; // Comando SQL para inserir dados
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setString(1, vencedor); // Define o vencedor
            statement.setString(2, tabuleiro); // Define o estado do tabuleiro
            statement.executeUpdate(); // Executa a inserção
        } catch (SQLException e) {
            e.printStackTrace(); // Imprime a pilha de erros se ocorrer uma exceção
        }
    }

    // Método para obter a pontuação do banco de dados
    public int[] obterPontuacao() {
        int[] pontuacoes = new int[2]; // Array para armazenar as pontuações do jogador e do computador
        String sql = "SELECT COUNT(*) FROM partidas WHERE vencedor = 'Jogador'"; // SQL para contar as vitórias do jogador
        try (Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(sql)) {
            if (resultSet.next()) {
                pontuacoes[0] = resultSet.getInt(1); // Armazena a pontuação do jogador
            }
        } catch (SQLException e) {
            e.printStackTrace(); // Imprime a pilha de erros se ocorrer uma exceção
        }

        sql = "SELECT COUNT(*) FROM partidas WHERE vencedor = 'Computador'"; // SQL para contar as vitórias do computador
        try (Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(sql)) {
            if (resultSet.next()) {
                pontuacoes[1] = resultSet.getInt(1); // Armazena a pontuação do computador
            }
        } catch (SQLException e) {
            e.printStackTrace(); // Imprime a pilha de erros se ocorrer uma exceção
        }

        return pontuacoes; // Retorna o array com as pontuações
    }
}
