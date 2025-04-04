package com.mycompany.projetoyoutube;

public class ProjetoYoutube {

    public static void main(String[] args) {
        Video v[] = new Video[3];
        v[0] = new Video("Resident Evil 4 remake moleke");
        v[1] = new Video("Painel carro pokebola");
        v[2] = new Video("Eu vou ser pai");
                
        Gafanhoto g[] = new Gafanhoto[2];
        g[0] = new Gafanhoto("Craudio", 12, "M", "crau");
        g[1] = new Gafanhoto("Josefa", 23, "F", "fafa");
        
        Visualizacao vis[] = new Visualizacao[5];
        vis[0] = new Visualizacao(g[0], v[2]);
        vis[0].avaliar();
        System.out.println(vis[0].toString());
        vis[1] = new Visualizacao(g[0], v[1]);
        vis[1].avaliar(3);
        System.out.println(vis[0].toString());

    }
}
