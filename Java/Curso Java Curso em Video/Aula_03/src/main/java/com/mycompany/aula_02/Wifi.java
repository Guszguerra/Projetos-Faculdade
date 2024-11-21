package com.mycompany.aula_02;

public class Wifi {
    String frequencia;
    int velocidadeUp;
    int velocidadeDown;
    int alcance;
    String operadora;
    boolean estaConectado;
    
    void Status(){
        System.out.println("Status da sua conexão wifi: ");
        System.out.println("Frequencia: " + frequencia + "ghz");
        System.out.println("Velocidade Upload: " + velocidadeUp);
        System.out.println("Velocidade Download: " + velocidadeDown);
        System.out.println("Alcance: " + alcance);
        System.out.println("Operadora: " + operadora);
    }
    
    void Conectar(){
        if(estaConectado == true)
            System.out.println("Voce ja esta conectado.");
        else
            System.out.println("Conectado.");
    }
    
    void Desconectar(){
        if(estaConectado == false)
            System.out.println("Voce já esta desconectado.");
        else
            System.out.println("Desconectado.");
    }
    
}
