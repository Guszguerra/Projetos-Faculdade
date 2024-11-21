package com.mycompany.aula06l05;

public class Aula06l05 {

    public static void main(String[] args) {
        ContaBanco conta1 = new ContaBanco();
        
        conta1.setNumConta(0001);
        conta1.setDono("Josue");
        conta1.estadoAtual();
        
        conta1.abrirConta("CC");
        conta1.depositar(100);
        conta1.estadoAtual();
        
        ContaBanco conta2 = new ContaBanco();
        
        conta2.abrirConta("CP");
        conta2.setDono("Maria");
        conta2.setNumConta(2222);
        conta2.depositar(500);
        conta2.sacar(100);
        conta2.fecharConta();
        conta2.estadoAtual();
    }
}
