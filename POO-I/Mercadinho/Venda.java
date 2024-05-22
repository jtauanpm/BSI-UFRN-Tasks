public class Venda
{
    private String data;
    private Item[] itens;
    
    public Venda(){}
    
    public String getData(){
        return this.data;
    }
    
    public void setData(String data){
        this.data = data;
    }
    
    public Item[] getItens(){
        return this.itens;
    }
    
    public void setItens(Item[] itens){
        this.itens = itens;
    }
    
    public double total(){
        double sum = 0;
        for(Item item : itens){
            sum = sum + item.total();    
        }
        return sum;
    }
    
}
