import java.util.*;
//throw
class Myex extends Exception {
    String strError;

    public Myex(String s) {
        super();
        strError = s;
    }

    public void disp() {
        System.out.println("Exception is: " + strError);
    }
}

class program8 {
    public static void main(String args[]) {
        int a, b, c;
        Scanner s = new Scanner(System.in);

        try {
            System.out.print("Enter two numbers: ");
            a = s.nextInt();
            b = s.nextInt();

            if (b == 0) {
                throw new Myex("divisor is Zero, not possible");
            }

            c = a / b;
            System.out.println("The result of the division is " + c);
        } catch (Myex m) {
            m.disp();
        } catch (Exception e) {
            System.out.println("Some error occurred");
        }
    }
}
