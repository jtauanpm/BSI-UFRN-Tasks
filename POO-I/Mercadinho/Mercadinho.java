public class Mercadinho
{   
    String nome;
    private Venda[] vendas;
        
    public Mercadinho(String nome){
        this.nome = nome;
    }
    
    public Venda[] getVendas(){
        return this.vendas;
    }
    
    public void setVendas(Venda[] vendas){
        this.vendas = vendas;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public double totalVendas(String data){
        double sum = 0;
        for (Venda venda : vendas){
            if(data.equals(venda.getData())){
                sum = sum + venda.total();
            }
        }
        return sum;
    }
    
    public double totalVendas(){
        double sum = 0;
        for (Venda venda : vendas){
            sum = sum + venda.total();
        }
        
        return sum;
    }
}
