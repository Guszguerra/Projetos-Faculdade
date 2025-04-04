package com.mycompany.projetopessoas;

public class Professor extends Pessoa {

    private String especialidade;
    private float salario;
    
    private void receberAumento(float aum){
        this.salario += aum;
    }

    public String getEspecialidade() {
        return especialidade;
    }

    public float getSalario() {
        return salario;
    }

    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }
    
    
}
