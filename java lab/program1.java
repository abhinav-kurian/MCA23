import java.io.BufferedReader;
import java.io.InputStreamReader;

class Num {
    int a;

    public void read() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.println("Enter the value:");
            a = Integer.parseInt(br.readLine());
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public void disp() {
        System.out.println("The value is " + a);
    }

    public Num add(Num q) {
        Num temp = new Num();
        temp.a = a + q.a;
        return temp;
    }
}

class program1 {
    public static void main(String args[]) {
        Num p, q, r;
        p = new Num();
        q = new Num();
        p.read();
        q.read();
        r = p.add(q);
        p.disp();
        q.disp();
        r.disp();
    }
}