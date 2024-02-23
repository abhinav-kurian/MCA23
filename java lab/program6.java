import java.io.*;

// Exception handling
class program6 {
    public static void main(String[] args) {
        int a, b, c;
        DataInputStream din = new DataInputStream(System.in);
        String s;
        try {
            System.out.println("Enter first number:");
            s = din.readLine();
            a = Integer.parseInt(s);

            System.out.println("Enter second number:");
            s = din.readLine();
            b = Integer.parseInt(s);
            c = a / b;
            System.out.print("c= " + c);
        } catch (IOException e1) {
            System.out.print("Unable to read from I/O device: " + e1);
        } catch (NumberFormatException e2) {
            System.out.print("Input String not a Number: " + e2);
        } catch (ArithmeticException e3) {
            System.out.println("Divider is Zero: " + e3);
        } catch (Exception e4) {
            System.out.print("Unknown Error: " + e4);
        }
    }
}
