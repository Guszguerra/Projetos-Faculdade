package com.mycompany.projetolivro;

public class Pessoa {
    //Atributos
    
    private String nome;
    private int idade;
    private String sexo;
    
    //Construtor
    
    public Pessoa(String n, int i, String s){
        this.nome = n;
        this.idade = i;
        this.sexo = s;
    }
    
    //Getters e Setters
    
    public String getNome(){
        return this.nome;
    }
    
    public void setNome(String n){
        this.nome = n;
    }
    
    public int getIdade(){
        return this.idade;
    }
    
    public void setIdade(int i){
        this.idade = i;
    }
    
    public String getSexo(){
        return  this.sexo;
    }
    
    public void setSexo(String s){
        this.sexo = s;
    }
    
    //Métodos
    
    public void fazerAniver(){
        this.setIdade(this.getIdade() + 1);
    }
}
