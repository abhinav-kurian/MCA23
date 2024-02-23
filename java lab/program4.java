import java.io.*;
// multiple iterface implimentation
interface Interface1 {
    void disp();
}

interface interface2 {
    void print();
}

class c1 implements Interface1, interface2 {
    public void disp() {
        System.out.print("In disp i1");
    }

    public void print() {
        System.out.print("In print i2");
    }
}

class program4 {
    public static void main(String args[]) {
        c1 obj = new c1();
        obj.disp();
        obj.print();
    }
}
