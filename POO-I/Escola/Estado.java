public class Estado
{
    private String nome;
    private Cidade[] cidades;
     
    public Estado(String nome){
        this.nome = nome;
        cidades = new Cidade[900];
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public Cidade[] getCidades(){
        return this.cidades;
    }
    
    public void setCidades(Cidade[] cidades){
        this.cidades = cidades;
    }
    
    public double mediaLeitura(){
        double sum = 0;
        for(Cidade cidade : cidades){
            sum = sum + cidade.mediaLeitura();
        }
        return sum/cidades.length;
    }
}
