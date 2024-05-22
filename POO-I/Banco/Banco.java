import java.util.ArrayList;

public class Banco
{
    private ArrayList<Agencia> agencias = new ArrayList<Agencia>();
    
    public double totalDinheiro(){
        return agencias.stream().mapToDouble(a->a.totalDinheiro()).sum();
    }
}
