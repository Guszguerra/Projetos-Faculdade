package com.mycompany.aula06l05;

public class ContaBanco {
    //Atributos
    public int numConta;
    protected String tipo;
    private String dono;
    private double saldo;
    private boolean status;
    //Construtor
    public ContaBanco(){
        this.saldo = 0;
        this.status = false;
    }
    //Metodos especiais
    public void setNumConta(int n){ //Metodo setter para numero da conta, para definir
        this.numConta = n; //define o valor passado como argumennto como numCotna
    }
    
    public int getNumConta(){ //Método getter para n da conta, para informar
        return this.numConta; //Retorna o valor dentro de numConta
    }
    
    public void setTipo(String t){ //Metodo setter para tipo da conta, para definir
        this.tipo = t; //define o valor passado como argumento como tipo
    }
    
    public String getTipo(){
        return tipo; //Retorna o valor dentro de tipo
    }
    
    public void setDono(String d){ //metodo setter para definir o dono da conta
        this.dono = d; //definindo como dono da conta o valor passado como argumento
    }
    
    public String getDono(){
        return this.dono; //Retorna o nome do dono
    }
    
    public void setSaldo(double s){
        this.saldo = s;
    }
    
    public double getSaldo(){
        return this.saldo;   
    }
    
    public void setStatus(boolean s){
        this.status = s;
    }
    
    public boolean getStatus(){
        return this.status;
    }
    
    //Metodos
    
    public void estadoAtual(){
        System.out.println("-------------------------------------");
        System.out.println("Status da Conta: " + this.getStatus());
        System.out.println("Dono da Conta: " + this.getDono());
        System.out.println("Saldo na Conta: " + this.getSaldo());
        System.out.println("Tipo da Conta: " + this.getTipo());
        System.out.println("Numero da Conta: " + this.getNumConta());
        System.out.println("-------------------------------------");
    }
    
    public void abrirConta(String t){ //Para abrir uma conta
        this.setTipo(t);
        this.setStatus(true);
        
        if(t == "CC"){
            this.setSaldo(50.0);
        }
        
        else if(t == "CP"){
            this.setSaldo(150.0);
        }
        System.out.println("Conta aberta com sucesso");
    }
    
    public void fecharConta(){ //Para fechar uma conta
        
        if(this.saldo > 0){
            System.out.println("Retire seu dinheiro da conta antes.");
        }
        
        else if(this.saldo < 0){
            System.out.println("Quite seus debitos antes de fechar sua conta.");
        }
        
        else{
            if(this.status == true)
                this.setStatus(false);
            System.out.println("Conta fechada com sucesso.");
        }
        
    }
    
    public void depositar(double v){
        if(this.status == true){
            this.setSaldo(this.getSaldo()+ v);
            System.out.println("Deposito realizado na conta de: " + this.getDono());
        }
        
        else{
            System.out.println("Abra a conta antes.");
        }
        
    }
    
    public void sacar(int v){
        
        if(getStatus()== true){
            
            if(v > getSaldo()){
                System.out.println("Digite um valor no seu orçamento.");
            }
            else{
                setSaldo(getSaldo() - v);
            }
            
        }
        
        else{
            System.out.println("Abra uma conta antes");
        }
        
    }
    
    public void pagarMensal(){
        double v = 0;
        
        if(getTipo()== "CC"){
            v = 12.0f; 
        }
        
        else if(getTipo() == "CP"){
            v = 20.0f;
        }
        
        if(getStatus() == true){
            if(getSaldo()> v){
                setSaldo(getSaldo() - v);
                System.out.println("Conta paga com sucesso por: "+ this.getDono());
            }
            else
                System.out.println("Impossivel pagar com conta fechada.");
        }
        
    }
}
