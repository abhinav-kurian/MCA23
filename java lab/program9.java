//Addition and Multiplication 
import java.io.*;

class num {
    DataInputStream din = new DataInputStream(System.in);
    int real, imag;

    public void read() {
        try {
            System.out.print("Enter Real Number: ");
            real = Integer.parseInt(din.readLine());
            System.out.print("Enter Imag Number: ");
            imag = Integer.parseInt(din.readLine());
        } catch (Exception e) {
            System.out.println("Error " + e);
        }
    }

    public void disp() {
        System.out.println("Real: " + real + " Imaginary: " + imag);
    }

    public num add(num q) {
        num t = new num();
        t.real = real + q.real;
        t.imag = imag + q.imag;
        return t;
    }

    public num mult(num q) {
        num t = new num();
        t.real = (real * q.real) - (imag * q.imag);
        t.imag = (real * q.imag) - (imag * q.real);
        return t;
    }
}

public class program9
 {
    public static void main(String[] args) {
        num p, q, r;
        p = new num();
        q = new num();
        p.read();
        q.read();
        r = p.add(q);
        r.disp();
        r = p.mult(q);
        r.disp();
    }
}