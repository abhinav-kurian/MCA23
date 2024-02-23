import java.io.*;
class Sum
{
public static void main(String args[])
{
DataInputStream num;
String s;
int a;
int b;
num=new DataInputStream(System.in);
try{
System.out.println("Enter the first number");
s=num.readLine();
a=Integer.parseInt(s);
System.out.println("Enter the second number");
s=num.readLine();
b=Integer.parseInt(s);
System.out.println("sum of " +a+ "and" + b+ "is " +(a+b));
}
catch(Exception e)
{
System.out.println("error"+e);
}
}
}