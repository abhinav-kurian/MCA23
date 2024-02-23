import java.io.*;
class Swap{
	public static void main(String args[])
	{
 		DataInputStream num; 
		String s;
		int a;
 		int b;
 		int temp=0;
		num=new DataInputStream(System.in);
	try{
		System.out.println("Enter the first number");
		s=num.readLine();
		a=Integer.parseInt(s);
		System.out.println("Enter the second  number");
		s=num.readLine();
		b=Integer.parseInt(s);
		System.out.println("Before swap A="+a+"and B="+b);
		temp=a;
		a=b;
		b=temp;
		System.out.println("After swap A="+a+"and B="+b);

	}
	catch(Exception e)	
	{
	 System.out.println(e);
	}
	}
      }