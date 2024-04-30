 import java.util.Scanner;

public class array {
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the number of elements");
       int n= s.nextInt();
       int[] ar= new int[n];
       for(int i=0;i<n;i++)
       {
           
            ar[i]=s.nextInt();
       }
       for(int i=0;i<n;i++)
       {
           
           System.out.print( ar[i]);
       }

    } 
    
}
