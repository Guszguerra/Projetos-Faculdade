package com.mycompany.aula_02;
public class Aula_02 {

    public static void main(String[] args) {
        Caneta c1 = new Caneta(); //instanciando o objeto caneta c1
        
        c1.modelo = "BIC cristal";
        c1.cor = "Azul";
        //c1.ponta = 0.5;
        c1.carga = 80;
       // c1.tampada = true;
        c1.destampar();
        c1.Status();
        c1.rabiscar();
    }
}
