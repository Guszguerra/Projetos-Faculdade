package com.mycompany.projetopessoas;
    
public class Aluno extends Pessoa {
    private int mat;
    private String curso;
    
    public void cancelarMatr(){
        System.out.println("A matricula será cancelada.");
    }

    public int getMat() {
        return mat;
    }

    public String getCurso() {
        return curso;
    }

    public void setMat(int mat) {
        this.mat = mat;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }
    
    
    
    
}
