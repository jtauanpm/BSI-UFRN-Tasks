public class Rede
{
    private String nome;
    private Mercadinho[] mercadinhos;
    
    public Rede(String nome){
        this.nome = nome;
    }
    
    public Mercadinho[] getMercados(){
        return this.mercadinhos;
    }
    
    public void setMercados(Mercadinho[] mercadinhos){
        this.mercadinhos = mercadinhos;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    } 
    
    public double total(){ 
        double sum = 0;
        for(Mercadinho mercadinho : mercadinhos){
            sum = sum + mercadinho.totalVendas();
        }
        
        return sum;
    }
    
    public double total(String data){ 
        double sum = 0;
        for(Mercadinho mercadinho : mercadinhos){
            sum = sum + mercadinho.totalVendas(data);
        }
        
        return sum;
    }
    
}
