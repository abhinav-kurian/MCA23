class a{
    int age;
    String name;
    
    public void disp() 
{
    System.out.println("name");
}
}
class b extends a{

    public void disp() 
{
    super.disp();
   
    System.out.println("name2");
}
}
 public class functionoverridding{
    public static void main(String []args){
     b obj2 = new b();
     obj2.disp();
    }
 }