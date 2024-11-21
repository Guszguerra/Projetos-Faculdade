package com.mycompany.jogodavelha;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class BancoDeDados {
    private static final String URL = "jdbc:mysql://localhost:3306/jogovelha"; // URL do banco de dados
    private static final String USER = "root"; // Usuário do banco de dados
    private static final String PASSWORD = "Mitaka73289135."; // Senha do banco de dados

    // Método para salvar a partida no banco de dados
    public void salvarPartida(String vencedor, String tabuleiroFinal) {
        String sql = "INSERT INTO partidasjogodavelha (vencedor, tabuleiroFinal) VALUES (?, ?)";
        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, vencedor); // Define o vencedor
            pstmt.setString(2, tabuleiroFinal); // Define o estado final do tabuleiro
            pstmt.executeUpdate(); // Executa a atualização no banco de dados
        } catch (SQLException e) {
            e.printStackTrace(); // Imprime a pilha de erros se ocorrer uma exceção
        }
    }

    // Método para contar as vitórias de um jogador no banco de dados
    public int contarVitorias(String vencedor) {
        String sql = "SELECT COUNT(*) FROM partidasjogodavelha WHERE vencedor = ?";
        try (Connection conn = DriverManager.getConnection(URL, USER, PASSWORD);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, vencedor); // Define o jogador vencedor
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    return rs.getInt(1); // Retorna o número de vitórias
                }
            }
        } catch (SQLException e) {
            e.printStackTrace(); // Imprime a pilha de erros se ocorrer uma exceção
        }
        return 0; // Retorna 0 se não houver vitórias registradas
    }
}
