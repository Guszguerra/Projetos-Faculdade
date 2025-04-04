package aula04;

public class Caneta {
    public String modelo;
    private float ponta;
    private String cor;
    private boolean tampada;
    
    //Construtor
    
    public Caneta(String c, String m, float p){ //metodo construtor
        this.tampar();
        this.cor = c;
        this.modelo = m;
        this.ponta = p;
    }

    
    public String getModelo(){ //função para obter o modelo da caneta,retorna o modelo em String(texto)
        return this.modelo;
    }
    
    public void setModelo(String m){ //função para definir o modelo da caneta, tem um parametro de string(texto) e define o modelo com o valor passado como argumento
        this.modelo = m;
    }
    
    public float getPonta(){ //Função para obter a ponta da caneta, retorna o valor em float
        return this.ponta;
    }
    
    public void setPonta(float p){ //Função para definir o valor da ponta, tem como parametro um numero float e define ponta com o valor passado como argumento.
        this.ponta = p;
    }
    
    public void tampar(){
        this.tampada = true;
    }
    
    public void destampar(){
        this.tampada = false;
    }
    
    public void status(){
        System.out.println("Uma caneta da(o): " + this.getModelo() + ".");
        System.out.println("Com uma ponta: " + this.getPonta() + ".");
        System.out.println("De cor: " + this.cor + ".");
        System.out.println("Esta: " + this.tampada + ".");
    }
}
