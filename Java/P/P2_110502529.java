package Java.P;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class P2_110502529 {
    
    public static void main(String[] args) {
        
        try{
            FileReader fr = new FileReader("test.txt");
            BufferedReader br = new BufferedReader(fr);

            FileWriter fw = new FileWriter("110502529.txt");
            BufferedWriter bw = new BufferedWriter(fw);

            String line;
            while((line=br.readLine())!=null){
                bw.write(line);
            }

            bw.flush();
            br.close();
            bw.close();

        }
        catch(IOException e){System.out.println(e);}
        
    }
}
