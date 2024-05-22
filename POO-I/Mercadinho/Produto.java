public class Produto
{
    private String descricao;
    private double preco;
    double vendas;
    
    public Produto(String desc){
        this.descricao = desc;
    }
    
    public double getVendas(){
        return this.vendas;
    }
    
    public void setVendas(double vendas){
        this.vendas = vendas;
    }
    
    public double getPreco() {
        return preco;
    }
    
    public void setPreco(double preco){
        this.preco = preco;
    }
    
    public String getDescricao() {
        return descricao;
    }
    
    public void setDescricao(String descricao){
        this.descricao = descricao;
    }
    
}
