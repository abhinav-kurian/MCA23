import java.io.*;
class Search

{
public static void main(String args[])
{
DataInputStream num;
String s;
int i;
int n;
int k;
int flag=0;
try{
num=new DataInputStream(System.in);
System.out.println("Enter the size");
s=num.readLine();
n=Integer.parseInt(s);
int a[];
a=new int[n];
System.out.println("Enter the Elements");
for(i=0;i<n;i++)
{
	a[i]=Integer.parseInt(num.readLine());
}
System.out.println("Enter the Element to search");
k=Integer.parseInt(num.readLine());
for(i=0;i<n;i++)
{
	if(a[i]==k)
{
        flag=1;
 	System.out.println("Element found at position " + (i+1));
}
}
if(flag==0)
{
	System.out.println("Element not found");
 }
}
catch(Exception e)
{
System.out.println("error"+e);
}
}
}
