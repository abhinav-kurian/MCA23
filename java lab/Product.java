import java.io.*;
public class Product
{
public static void main(String args[])
{
DataInputStream in=new DataInputStream(System.in);
try
{
System.out.println("Enter the first number: ");
int a=Integer.parseInt(in.readLine());
System.out.println("Enter the second number: ");
int b=Integer.parseInt(in.readLine());
System.out.println("Product = "+(a*b));
}
catch(Exception e)
{
System.out.println("Error "+e);
}
}
}