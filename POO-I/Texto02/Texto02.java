import java.util.Arrays;
public class Texto02
{    
    public int[] exercicio2_2(int i1, int i2){
        int[] result = new int[2];
        if (i1 > i2){
            result[0] = i1;
            result[1] = i2;
            return result;
        }
        result[0] = i2;
        result[1] = i1;
        return result;
    }
    
    public double[] exercicio2_3(double r1, double r2, double r3){
        double[] result = new double[3];
        result[0] = r1;
        result[1] = r2;
        result[2] = r3;
        
        for(int i = 0;i<result.length;i++) {
            result[i]=-result[i];
        }
        
        Arrays.sort(result);

        for(int i = 0;i<result.length;i++) {
            result[i]=-result[i]; 
        }   
        
        return result;
    }
    
    public double exercicio2_4(double num){
        return Math.sqrt(num);
    }
       
    public boolean exercicio2_5(String str1, String str2){
        if(str2.indexOf(str1) < 0){
            return false;   
        }
        return true;
    }
    
    public String[] exercicio2_6(String str1, String str2){
        int c1, c2;
        c1 = str1.compareTo(str2);
        c2 = str2.compareTo(str1);
        
        if(c1 > c2){
            return new String[]{str2, str1};
        }
        return new String[]{str1, str2};
    }
    
        public String[] exercicio2_7(String str1, String str2, String str3){
        String[] result = exercicio2_6(str1,str2);
        
        if(str3.compareTo(result[0]) < 0){
            return new String[]{str3, result[0], result[1]};
        }else if(str3.compareTo(result[1]) < 0){
            return new String[]{result[0], str3, result[1]};
        }
        return new String[]{result[0], result[1], str3};
        
    }
    
    public String exercicio2_8(String name){
        String result;
        int index;
        index = name.indexOf(" ");
        return name.substring(index,name.length()) + ", " + name.substring(0,index);
    }
    
    public String[] exercicio2_9(String[] strs){
        for(int i = 0; i < strs.length; i++){
            strs[i] = strs[i].toUpperCase();
        }
        return strs;
    }
    
    public String[] exercicio2_10(String[] strs){
        String[] result = new String[strs.length];
        for(int i = 0; i < strs.length; i++){
            result[i] = strs[i].toUpperCase();
        }
        return result;
    }
    
    public int[] exercicio2_11(int[] ints){
        int ass;
        for(int i = 0; i < ints.length-1; i++){
            if (ints[i] > ints[i+1]){
                ass = ints[i];
                ints[i] = ints[i+1];
                ints[i+1] = ass;
            }
        }
        return ints;
    }
        public int exercicio2_12(int[] ints){
        int ass, count = 0;
        for(int i = 0; i < ints.length-1; i++){
            if (ints[i] > ints[i+i]){
                ass = ints[i];
                ints[i] = ints[i+1];
                ints[i+1] = ass;
                count++;
            }
        }
        return count;
    }
    
        public int exercicio2_13(String[] strs){
        int count = 0;
        String ass;
        for(int i = 0; i < strs.length-1; i++){
            if (strs[i].compareTo(strs[i+1]) > 0){
                ass = strs[i];
                strs[i] = strs[i+1];
                strs[i+1] = ass;
                count++;
            }
        }
        return count;
    }
    
    public int[] exercicio2_14(int[] ints){
        for(int i = 0;i<ints.length;i++) {
            ints[i]=-ints[i];
        }
        
        Arrays.sort(ints);

        for(int i = 0;i<ints.length;i++) {
            ints[i]=-ints[i]; 
        }   
        
        return ints;
    }
    
    public String[] exercicio2_15(String[] strs){
        String ass;
        while(exercicio2_13(strs) !=0){
            for(int i = 0; i < strs.length-1; i++){
                if (strs[i].compareTo(strs[i+1]) > 0){
                    ass = strs[i];
                    strs[i] = strs[i+1];
                    strs[i+1] = ass;
                }
            }
        }
        return strs;
    }
    
    public String[] invertName(String[] names){
        int index;
        for(int i=0; i<names.length;i++){
            index = names[i].indexOf(" ");
            names[i] = names[i].substring(index+1,names[i].length()) + " " + names[i].substring(0,index);
        }
        return names;
    }
    
    public String[] exercicio2_16(String[] names){
        names = invertName(names);
        names = exercicio2_15(names);
        names = invertName(names);
        return names;
    }
    
    public String[] exercicio2_17(String[] names){
        int index;
        names = exercicio2_16(names);
        for(int i = 0; i < names.length; i++){
            index = names[i].indexOf(" ");
            names[i] = names[i].substring(index,names[i].length()) + ", " + names[i].substring(0,index);
        }
        return names;
    }
}
