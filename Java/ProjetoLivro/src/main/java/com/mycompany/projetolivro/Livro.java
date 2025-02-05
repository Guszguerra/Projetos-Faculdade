package com.mycompany.projetolivro;
public class Livro implements Publicacao{
    
    //Atributos
    
    private String titulo;
    private String autor;
    private int totPaginas;
    private int pagAtual;
    private boolean aberto;
    private Pessoa leitor;
    
    //Construtor
    
    public Livro(String t, String au, int tP, Pessoa leitor){
        
        this.titulo = t;
        this.autor = au;
        this.totPaginas = tP;
        this.pagAtual = 0;
        this.aberto = false;
        this.leitor = leitor;

    }
    
    //Getters e Setters
    
    public String getTitulo(){
        return this.titulo;
    }
    
    public void setTitulo(String t){
        this.titulo = t;
    }
    
    public String getAutor(){
        return this.autor;
    }
    
    public void setAutor(String au){
        this.autor = au;
    }
    
    public int getTotPaginas(){
        return this.totPaginas;
    }
    
    public void setTotPaginas(int tP){
        this.totPaginas = tP;
    }
    
    public int getPagAtual(){
        return this.pagAtual;
    }
    
    public void setPagAtual(int pA){
        this.pagAtual = pA;
    }
    
    public boolean getAberto(){
        return this.aberto;
    }
    
    public void setAberto(boolean ab){
        this.aberto = ab;
    }
    
    public Pessoa getLeitor(){
        return leitor;
    }
    
    public void setLeitor(Pessoa leitor){
        this.leitor = leitor;
    }
    
    //Métodos

    public String detalhes() {
        return "Livro{" + "titulo=" + titulo + ", autor=" + autor + 
                ", totPaginas=" + totPaginas + ", pagAtual=" + pagAtual + ", aberto=" + aberto + ", leitor=" + leitor.getNome() + '}';
    }
    

    
    
    //Métodos Interface
    @Override
    public void abrir() {
        if(this.getAberto()) //Se ja tiver aberto exibir msg
            System.out.println("Nao tem como abrir pois o livro ja está aberto.");
        else //Se não
            this.setAberto(true); //Chamar o setAberto passando o valor ture, assim mudando aberto para verdadeiro
    }

    @Override
    public void fechar() {
        if(this.getAberto())
            this.setAberto(false);
        else
            System.out.println("Nao da pra fechar pois o livro ja esta fechado.");
    }

    @Override
    public void folhear(int p) {
        this.pagAtual = p;
    }

    @Override
    public void avancarPag() {
        if(this.getAberto()){ //Se o livro estiver aberto
            
            if(this.getPagAtual()<this.getTotPaginas())//Se a pág atual for menor que o número total de páginas
                this.setPagAtual(this.getPagAtual() + 1); //Setar a pag atual pro prox numero
            else //(Se o numero total de paginas for menor ou igual a pag atual
            System.out.println("Nao tem como avançar pois chegou ao final do livro.");
            
        }
        else{ //Se estiver fechado
            System.out.println("Abra o livro antes de avancar a pagina.");
        }
        
    }       

    @Override
    public void voltarPag() {
        
        if(this.getAberto()){ //Se o livro estiver aberto
            
            if(this.getPagAtual() > 1) //Se o numero da pag atual for maior q um
                this.setPagAtual(this.getPagAtual() - 1); //Setar o numero da pag pro n anterior
            else //Se o n da pag for igual ou menor q 1
            System.out.println("Nao ha mais páginas para voltar.");
            
        }
        else{
            System.out.println("Abra o livro antes de tentar voltar uma página");
        }
        
    }
    
}