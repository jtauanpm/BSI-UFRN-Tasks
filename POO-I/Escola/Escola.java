import java.util.ArrayList;
public class Escola
{
    private String nome;
    private ArrayList<Estudante> estudantes;
     
    public Escola(String nome){
        this.nome = nome;
        this.estudantes = new ArrayList<>();
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public ArrayList<Estudante> getEstudantes(){
        return this.estudantes;
    }
    
    public void setEstudantes(ArrayList<Estudante> estudantes){
        this.estudantes = estudantes;
    }  
    
    public void addEstudantes(Estudante estudante){
        this.estudantes.add(estudante);
    }  
    
    public double mediaLeitura(){
        double sum = 0;
        for(Estudante estudante : estudantes){
            sum = sum + estudante.getNivelLeitura();
        }
        return sum/estudantes.size();
    }
    
    public ArrayList<Estudante> mediaAcima(){
        ArrayList<Estudante> mediaAcima = new ArrayList<>();
        double media = mediaLeitura();
        for(Estudante estudante : estudantes){
            if(estudante.getNivelLeitura() > media){
                mediaAcima.add(estudante);
            }
        }
        return mediaAcima;
    }
    
    public ArrayList<Estudante> mediaAcima(double media){
        ArrayList<Estudante> mediaAcima = new ArrayList<>();
        for(Estudante estudante : estudantes){
            if(estudante.getNivelLeitura() > media){
                mediaAcima.add(estudante);
            }
        }
        return mediaAcima;
    }
}
