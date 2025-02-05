package com.mycompany.aula06;

public class ControleRemoto implements Controlador{
//Atributos
    private int volume;
    private boolean ligado;
    private boolean tocando;
    
//Construtor
    
    public ControleRemoto(){
        this.volume = 50;
        this.ligado = false;
        this.tocando = false;
    }
    
//Métodos Especiais
    
    private int getVolume(){
        return this.volume;
    }
    
    private void setVolume(int v){
        this.volume = v;
    }
    
    private boolean getLigado(){
        return this.ligado;
    }
    
    private void setLigado(boolean l){
        this.ligado = l;
    }
    
    private boolean getTocando(){
        return this.tocando;
    }
    
    private void setTocando(boolean t){
        this.tocando = t;
    }

    @Override
    public void ligar() {
        this.setLigado(true);
    }

    @Override
    public void desligar() {
        this.setLigado(false);
    }

    @Override
    public void abrirMenu() {
        if (!(this.getLigado())){
            System.out.println("Impossivel abrir Menu.");
        }
        else {
            System.out.println("----- MENU -----");
            System.out.println("Esta ligado? " + this.getLigado());
            System.out.println("Esta tocando? " + this.getTocando());
            System.out.print("Volume: " + this.getVolume());

            for(int i=0; i <= this.getVolume(); i+=10){
                System.out.print("|");
            }
        }
   
    }

    @Override
    public void fecharMenu() {
        System.out.printf("\nFechando menu.....");
    }

    @Override
    public void maisVolume() {
        if(this.getLigado()){
            this.setVolume(this.getVolume() + 5);
        }
        else{
            System.out.println("Impossivel aumentar volume.");
        }
    }

    @Override
    public void menosVolume() {
        if(this.getLigado()){
            this.setVolume(this.getVolume() - 5);
        }
        else{
            System.out.println("Impossivel diminuir volume.");
        }
    }

    @Override
    public void ligarMudo() {
        if(this.getLigado()&& this.getVolume() > 0){
            System.out.println("Modo mudo ligado.");
            this.setVolume(0);
        }
    }

    @Override
    public void desligarMudo() {
        if(this.getLigado() && this.getVolume() == 0){
            this.setVolume(50);
        }
    }

    @Override
    public void play() {
        if(this.getLigado() && !(this.getTocando())){
            this.setTocando(true);
        }
        else{
            System.out.println("Impossivel dar play.");
        }
    }

    @Override
    public void pause() {
        if(this.getLigado() && this.getTocando()){
            this.setTocando(false);
        }
        else{
            System.out.println("Impossivel pausar.");
        }
    }
    
    
    
}
