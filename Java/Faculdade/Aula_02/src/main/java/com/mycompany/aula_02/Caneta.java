
package com.mycompany.aula_02;
public class Caneta { //Criando classe caneta
    String modelo; //vai ter um modelo
    String cor; //uma cor
    double ponta; //uma finura de ponta
    int carga; // qnt de cargas
    boolean tampada; //se esta tampada ou nao
    
    void Status(){
        
        System.out.println("Modelo: " + this.modelo); //this é como se fosse colocar o nomedoobj. , usado pra referenciar ele msm
        System.out.println("Uma caneta: " + this.cor + "" );
        System.out.println("Ponta: " + this.ponta);
        System.out.println("Carga: " + this.carga);
        System.out.println("Esta tampada: " + this.tampada);
    }
    
    void rabiscar(){
        if(this.tampada == true)
            System.out.println("Não da para rabiscar, esta tampada.");
        else
            System.out.println("Rabiscado.");
    }
    
    void tampar(){ //se voce quer tampar
        this.tampada = true;
    }
    
    void destampar(){
        this.tampada = false;
    }
    
    
    
}
