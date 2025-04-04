package com.mycompany.aula07;

public class Lutador {
    //Atributos
    
    private String nome;
    private String nacionalidade;
    private int idade;
    private float altura;
    private float peso;
    private String categoria;
    private int vitorias;
    private int derrotas;
    private int empates;
    
    //Métodos Especiais
    
    public Lutador(String no,String na, int id, float al, float pe, int vi, int de, int em){ //Construtor
        this.nome = no;
        this.nacionalidade = na;
        this.idade = id;
        this.altura = al;
        setPeso(pe);
        this.vitorias = vi;
        this.derrotas = de;
        this.empates = em;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public void setNome(String no){
        this.nome = no;
    }
    
    public String getNacionalidade(){
        return this.nacionalidade;
    }
    
    public void setNacionalidade(String nc){
        this.nacionalidade = nc;
    }
    
    public int getIdade(){
        return this.idade;
    }
    
    public void setIdade(int i){
        this.idade = i;
    }
    
    public float getAltura(){
        return this.altura;
    }
    
    public void setAltura(float a){
        this.altura = a;
    }
    
    public float getPeso(){
        return this.peso;
    }
    
    public void setPeso(float pe){
        this.peso = pe;
        setCategoria(); //SEMPRE Q CONFIGURAR(OU SETTAR) O PESO, TBM CONFIGURA A CATEGORIA
    }
    
    public String getCategoria(){
        return this.categoria;
    }
    
    private void setCategoria(){
        
       if(this.getPeso()< 52.2){
           this.categoria = "Invalido";
       }
       else if(this.getPeso() <= 70.3){
           this.categoria = "Leve";
       }
       else if(this.getPeso() <= 83.9){
           this.categoria = "Medio";
       }
       else if(this.getPeso() <= 120.2){
           this.categoria = "Pesado";
       }
       else{
           this.categoria = "Invalido";
       }
       
    }
    
    public int getVitorias(){
        return this.vitorias;
    }
    
    public void setVitorias(int v){
        this.vitorias = v;
    }
    
    public int getDerrotas(){
        return this.derrotas;
    }
    
    public void setDerrotas(int d){
        this.derrotas = d;
    }
    
    public int getEmpates(){
        return this.empates;
    }
    
    public void setEmpates(int e){
        this.empates = e;
    }
    
    //Métodos
    
    public void apresentar(){
        System.out.println("---------------------------------------");
        System.out.println("Lutador: " + this.getNome());
        System.out.println("Origem: " + this.getNacionalidade());
        System.out.println(this.getIdade() + " anos");
        System.out.println(this.getAltura() + "m de altura");
        System.out.println("Pesando: " + this.getPeso() + "Kg");
        System.out.println("Ganhou: " + this.getVitorias());
        System.out.println("Perdeu: " + this.getDerrotas());
        System.out.println("Empatou: " + this.getEmpates());
        System.out.println("---------------------------------------");
    }
    
    public void status(){
        System.out.println("---------------------------------------");
        System.out.println(this.getNome());
        System.out.println("E um peso: " + this.getCategoria());
        System.out.println(this.getVitorias() + " vitorias");
        System.out.println(this.getDerrotas() + " derrotas");
        System.out.println(this.getEmpates() + " empates");
        System.out.println("---------------------------------------");
    }
    
    public void ganharLuta(){
        this.setVitorias(this.getVitorias() + 1);
    }
    
    public void perderLuta(){
        this.setDerrotas(this.getDerrotas() + 1);
    }
    
    public void empatarLuta(){
        this.setEmpates(this.getEmpates() + 1);
    }
    
}
