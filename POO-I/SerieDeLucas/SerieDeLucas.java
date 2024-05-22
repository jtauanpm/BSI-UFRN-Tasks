import java.util.ArrayList;
public class SerieDeLucas
{
    int p, q;
    ArrayList<Integer> serie;
    
    public SerieDeLucas(int p, int q){
        this.p = p;
        this.q = q;
        serie = new ArrayList<Integer>();
        serie.add(0);
        serie.add(1);
    }
    
    public int proxTermo(){
        int termo;
        termo = p*(serie.get(serie.size()-1)) - q*(serie.get(serie.size()-2));
        serie.add(termo);
        return termo;
    }
    
    public int saltarTermo(int n){
        int index = n-1;
        while(serie.size() < n){
            proxTermo();
        }
        return serie.get(index);
    }
    
    public ArrayList<Integer> getSerie(){
        return serie;
    }
}
