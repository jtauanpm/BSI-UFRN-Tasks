import java.util.ArrayList;

public class Agencia
{
    private ArrayList<Conta> contas = new ArrayList<Conta>();
    private String codigo;
    
    void Agencia(String codigo){
        this.codigo = codigo;
    }
    
    public String getCodigo(){
        return codigo;
    }
    
    public double totalDinheiro(){
        return contas.stream().mapToDouble(c->c.getSaldo()).sum();
    }
    
    public void manutencaoContas(double valor){
        contas.stream().forEach(c->c.manutencao(valor));
    }
    
    public void renderContas(double valor){
        contas.stream().filter(c -> c.getTipo() == "cp").forEach(c->c.render(valor));
    }
    
    public Conta pesquisarConta(String codigo){
        return contas.stream().filter(c->c.codigo.compareTo(codigo) == 0).findFirst().get();
    }
    
    public boolean transferir(String contaOrigem, String contaDestino, double valor){
        Conta cd = pesquisarConta(contaDestino);
        Conta co = pesquisarConta(contaOrigem);    
        if((co == null) || (cd == null)){
            return false;
        }
        return co.transferir(valor, cd);
    }
}