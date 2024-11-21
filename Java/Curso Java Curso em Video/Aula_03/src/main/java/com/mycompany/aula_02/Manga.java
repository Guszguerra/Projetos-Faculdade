
package com.mycompany.aula_02;

public class Manga {
    String tipo;
    String tipoCapa;
    String genero;
    String editora;
    String autor;
    String nome;
    int paginas;
    int volumes;
    double preco;
    boolean aberto;
    
    void comprar(String nome, double preco){
        System.out.println("Voce acabou de comprar: " + nome + "por R$: " + preco);
    }
    
    void abrir(){
        if(aberto == true)
            System.out.println("O manga ja esta aberto.");
        else
            System.out.println("O manga esta aberto agora.");
    }
    
    void ler(){
        System.out.println("Voce leu a página.");
    }
}
