import java.io.*;
class Minimum

{
public static void main(String args[])
{
DataInputStream num;
String s;
int a;
int b;
int c;
int min;
num=new DataInputStream(System.in);
try{
System.out.println("Enter the first number");
s=num.readLine();
a=Integer.parseInt(s);
System.out.println("Enter the second number");
s=num.readLine();
b=Integer.parseInt(s);
System.out.println("Enter the third number");
s=num.readLine();
c=Integer.parseInt(s);
 min = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
System.out.println("Minimum is " +min);
}
catch(Exception e)
{
System.out.println("error"+e);
}
}
}
