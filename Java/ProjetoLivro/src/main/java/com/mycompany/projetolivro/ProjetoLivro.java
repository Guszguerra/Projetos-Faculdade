package com.mycompany.projetolivro;

public class ProjetoLivro {
    public static void main(String[] args) {
        Pessoa[] p = new Pessoa[2];
        Livro[] l = new Livro[3];
        
        p[0] = new Pessoa("Joao", 12, "M");
        p[1] = new Pessoa("Joana", 15, "F");
        
        l[0] = new Livro("Pequeno principe", "Gus Guanabara", 312, p[0]);
        l[1] = new Livro("csm", "Fujimoto", 92, p[1]);
        l[2] = new Livro("Coraline", "Neil Gaiman", 320, p[0]);
        
        System.out.println(l[2].detalhes());
        l[2].abrir();
        l[2].avancarPag();
        System.out.println(l[2].detalhes());
    }
}
