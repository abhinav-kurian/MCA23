//An interface Method can invoke other Method present  in the class
import java.io.*;
interface i1
{
public void disp();
public void print();
}
class c1 implements i1
{
public void disp()
{
System.out.println("interface disp");
}
public void print()
{
draw();
System.out.println("interface print");
}
private void draw()
{
System.out.println("Draw not in interface");
}
}
class interface2
{
public static void main(String args[])
{
i1 obj;
obj=new c1();
obj.disp();
obj.print();

}
}