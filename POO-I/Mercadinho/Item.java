public class Item
{
    private double preco;
    private int quantidade;
    private Produto produto;
    
    public Item(Produto produto)
    {
       this.produto = produto; 
    }
    
    public int getQuantidade() {
        return quantidade;
    }
    
    public void setQuantidade(int quantidade){
        this.quantidade = quantidade;
    }
    
    public Produto getProduto(){
        return this.produto;
    }
    
    public void setProduto(Produto produto){
        this.produto = produto;
    }
    
    public double getPreco(){
        return this.preco;
    }
    
    public void setPreco(double preco){
        this.preco = preco;
    }
    
    public double total(){
        return preco * quantidade;
    }
}
