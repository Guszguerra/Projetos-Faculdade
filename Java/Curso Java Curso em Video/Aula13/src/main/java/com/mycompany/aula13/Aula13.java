package com.mycompany.aula13;

public class Aula13 {

    public static void main(String[] args) {
          Mamifero x = new Mamifero();
          Cachorro k = new Cachorro();

          k.reagir("Ola");
          k.reagir("Vai apanhar");
          k.reagir(11, 45);
          k.reagir(21, 00);
          k.reagir(true);
          k.reagir(false);
          k.reagir(2, 12.5f);
          k.reagir(17, 4.5f);
    }
}
