package aula04;

public class Aula_04 {

    public static void main(String[] args) {
        
        Caneta c1 = new Caneta("BIC", "Azul", 0.5f);
        Caneta c2 = new Caneta("Cristal", "Vemelha", 1.5f);
        
        c1.status();
        c2.status();
    }
}
