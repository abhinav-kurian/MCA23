import java.io.*;
interface ishape{
public void draw();
public void move();
}
class line implements ishape
{
public void draw()
{
System.out.println("draw line");
}
public void move()
{
System.out.println("line move");
}
}
class circle implements ishape
{
public void draw()
{
System.out.println("draw circle");
}
public void move()
{
System.out.println("move circle");
}
}
class interface3
{
public static void main(String args[])
{
ishape obj;
obj=new line();
obj.draw();
obj.move();
obj=new circle();
obj.draw();
obj.move();
}
} 