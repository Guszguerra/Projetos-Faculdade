package com.mycompany.aula_02;
public class Aula_02 {

    public static void main(String[] args) {
        Caneta c1 = new Caneta(); //instanciando o objeto caneta c1
        c1.cor = "Azul"; //Cor da caneta c1 vai ser azul
        c1.ponta = 0.5f; //Vai ter ponta 0.5f
        c1.tampada = false; //Vai estar destampada.
        
        c1.tampar(); //tampando por função
        c1.Status();//Exibir os status
        c1.rabiscar(); //Tentando rabiscar
        
        Caneta c2 = new Caneta();
        
        c2.modelo = "Ferrari";
        c2.destampar();
        c2.Status();
        c2.rabiscar();
    }
}
