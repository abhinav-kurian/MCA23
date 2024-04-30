import java.io.*;
public class fileinputoutput {

    public static void main (String args[]) throws Exception{
        BufferedWriter write = new BufferedWriter( new FileWriter("a.txt"));
        write.write("hello all");
        write.close();

         
    }
  
}
    
    
    

