import java.util.ArrayList;
import java.time.LocalDate;
import java.time.Month;

public class Conta
{
    public String codigo;
    private String tipo;
    private double saldo;
    private double limite;
    private int anoManutencao;
    private Month mesManutencao;
    private ArrayList<Transacao> extrato = new ArrayList<Transacao>();
    
    void Conta(String codigo, String tipo){
        this.saldo = 0;
        this.tipo = tipo;
        this.codigo = codigo;
        anoManutencao = 0;
    }
    
    public String getTipo(){
        return this.tipo;
    }
    
    public void render(double valor){ // recebe porcentagem
        if(this.saldo > 0){
            this.saldo = this.saldo + (this.saldo*(valor/100));
            extrato.add(new Transacao("rendimento","rendimentos de conta poupanca",valor,this.saldo));
        }
    }
    
    public boolean sacar(double valor){
        if(valor > 0 & ((this.saldo + this.limite)>= valor)){
            this.saldo = this.saldo - valor;
            extrato.add(new Transacao("saque","",-1*valor,this.saldo));
            return true;
        }
        return false;
    }
    
    public double getSaldo(){
        return this.saldo;
    }
    
    public double deposito(double valor){
        this.saldo = this.saldo + valor;
        extrato.add(new Transacao("deposito","",valor,this.saldo));
        return this.saldo;
    }
    
    public boolean transferir(double valor, Conta contaDestino){
        if(sacar(valor)){
            contaDestino.deposito(valor);
            extrato.add(new Transacao("transferencia/saida","",-1*valor,this.saldo));
            contaDestino.extrato.add(new Transacao("transferencia/entrada","",valor,this.saldo));
            return true;
        }
        return false;
    }
    
    public boolean manutencao(double valor){ 
        LocalDate dataAtual = LocalDate.now();
        int anoAtual = dataAtual.getYear();
        Month mesAtual = dataAtual.getMonth();
        if((this.anoManutencao == 0) | !(mesAtual == this.mesManutencao && anoAtual == this.anoManutencao)){
            if(this.sacar(valor)){
                extrato.add(new Transacao("taxa","Taxa de manutencao da conta cobrada pela agencia",-1*valor,this.saldo));
                mesManutencao = mesAtual;
                anoManutencao = anoAtual;
                return true;
            }
        }
        return false;
    }
}
