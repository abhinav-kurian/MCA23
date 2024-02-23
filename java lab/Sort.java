import java.io.*;
class Sort

{
public static void main(String args[])
{
DataInputStream num;
String s;
int i;
int n;
int t;
int j;
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
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
       if(a[i]>a[j])
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
}
}
for(i=0;i<n;i++)
{
	System.out.print( a[i]+"\t" );
}

}
catch(Exception e)
{
System.out.println("error"+e);
}
}
}
