import java.util.Date;
import java.util.Locale;
import java.text.SimpleDateFormat;
import java.io.File;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;

public class Texto03{    
    
    public String exercicio3_1(){
        Date cuurentDate = new Date();
        String date = new SimpleDateFormat("dd/MM/yyyy").format(cuurentDate);
        return "" + new Date();
    }
    
    public String exercicio3_2(String data) throws Exception{
        return new SimpleDateFormat("EEEE, dd, MMM, yyyy").format(new SimpleDateFormat("dd/MM/yyyy"));
    }
    
    public String[] exercicio3_3(String dir){
        if (new File(dir).exists()) {
            return new File(dir).list();
        }
        return new String[]{null};
    }
    
    public String[] exercicio3_4(String dir) {
        File path = new File(dir);
        
        if (path.exists()) {
            String[] itens = path.list();
            for (int i=0; i<itens.length; i++) {
                if (new File(path.getPath() + "/" + itens[i]).isDirectory()) {
                    itens[i] = "[D]" + itens[i];
                } else {
                    itens[i] = "[A]" + itens[i];
                }
            }
            return itens;
        }
        return new String[] {null};
    }
    
    public boolean exercicio3_5(String path){
        File file = new File(path);
        if (file.exists()) {
            file.delete();
            return true;
        }
        return false;
        
    }
    
    public void exercicio3_6() {
        JFrame jframe = new JFrame();
        jframe.setTitle("Janela Com 2 Arquivos");
        jframe.setSize(300, 300);
        
        JMenuBar menuBar = new JMenuBar();
        jframe.setJMenuBar(menuBar);
        menuBar.add(new JMenu("Arquivo"));
        menuBar.add(new JMenu("Editar"));
        
        jframe.setVisible(true);
    }
    
    public boolean exercicio3_7(String path){
        File arquivo = new File(path);
        try {
            if (arquivo.exists()) {
                Runtime.getRuntime().exec(new String[] {"notepad", path});
                return true;
            } 
            return false;
        }
        catch (Exception e) {
            return false;
        }
    }
    
    public boolean exercicios3_8(String path){
        File file = new File(path);
        
        try {
            if(file.exists()) {
                Runtime.getRuntime().exec(new String[]{path});
                return true;
            }
            return false;
        }
        catch (Exception e) {
            return false;
        }
    }
    
    public void exercicio3_9(){
        JFrame jframe = new JFrame();
        jframe.setTitle("Janela Vazia");
        jframe.setExtendedState(jframe.MAXIMIZED_BOTH);
        jframe.setVisible(true);
    }
    
    public String exercicio3_10(String date1, String date2) throws Exception{
        String data1 = new SimpleDateFormat("dd/MM/yyyy").format(date1);
        String data2 = new SimpleDateFormat("dd/MM/yyyy").format(date2);
        
        if (data1.compareTo(data2)>0) {
            return data1;
        }
        return data2;
    }
    
    public Date[] exercicio3_11(String[] datas) throws Exception{
        Date[] dates = new Date[datas.length];
        for (int i=0; i<datas.length; i++) {
            dates[i] = new SimpleDateFormat("dd/MM/yyyy").parse(datas[i]);
        }
        return dates;
    }
    
    public String exercicio3_12(String date) throws Exception {           
        String day;
        day = new SimpleDateFormat("EEEE", new Locale("pt", "BR")).format(new SimpleDateFormat("dd/MM/yyyy").parse(date));
        return day;
    }
}
