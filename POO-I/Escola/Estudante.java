public class Estudante
{   
    private String cpf;
    private double nivelLeitura;
    
    public Estudante(String cpf){
        this.cpf = cpf;
    }
    
    public String getCpf(){
        return this.cpf;
    }
    
    public void setCpf(String cpf){
        this.cpf = cpf;
    }
    
    public double getNivelLeitura(){
        return this.nivelLeitura;
    }
    
    public void setNivelLeitura(double nivelLeitura){
        this.nivelLeitura = nivelLeitura;
    }
}
