import java.util.Date;

public class Transacao
{
    private String tipo;
    private String descricao;
    private double valor;
    private double saldo;
    private Date dataHora;
    
    public Transacao(String tipo, String descricao, double valor, double saldo){
        this.tipo = tipo;
        this.descricao = descricao;
        this.valor = valor;
        this.dataHora = new Date();
    }
    
    public void mostrarInfos(){
        System.out.println(dataHora);
        System.out.println("Tipo: " + this.tipo);
        System.out.println("Descricao: " + this.descricao);
        System.out.println("Valor: " + this.valor);        
    }
}
