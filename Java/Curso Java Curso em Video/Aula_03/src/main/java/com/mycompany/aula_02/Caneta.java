
package com.mycompany.aula_02;
public class Caneta { //Criando classe caneta
    public String modelo; //vai ter um modelo
    public String cor; //uma cor
    private double ponta; //uma finura de ponta
    protected int carga; // qnt de cargas
    private boolean tampada; //se esta tampada ou nao
    
    public void Status(){
        
        System.out.println("Modelo: " + this.modelo); //this é como se fosse colocar o nomedoobj. , usado pra referenciar ele msm
        System.out.println("Uma caneta: " + this.cor + "" );
        System.out.println("Ponta: " + this.ponta);
        System.out.println("Carga: " + this.carga);
        System.out.println("Esta tampada: " + this.tampada);
    }
    
    public void rabiscar(){
        if(this.tampada == true)
            System.out.println("Não da para rabiscar, esta tampada.");
        else
            System.out.println("Rabiscado.");
    }
    
    public void tampar(){ //se voce quer tampar
        this.tampada = true;
    }
    
    public void destampar(){
        this.tampada = false;
    }
    
    
    
}
