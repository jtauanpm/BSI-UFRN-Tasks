public class Cidade
{
    private String nome;
    private Escola[] escolas;
    
    public Cidade(String nome){
        this.nome = nome;
        escolas = new Escola[500];  
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public Escola[] getEscolas(){
        return this.escolas;
    }
    
    public void setEscolas(Escola[] escolas){
        this.escolas = escolas;
    }
    
    public double mediaLeitura(){
        double sum = 0;
        for(Escola escola : escolas){
            sum = sum + escola.mediaLeitura();
        }
        return sum/escolas.length;
    }
    
}
