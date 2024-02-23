import java.io.*;

class Largest {
    public static void main(String args[]) {
        DataInputStream num;
        String s;
        int a;
        int b;
        int c;
        int max;
        num = new DataInputStream(System.in);
        try {
            System.out.println("Enter the first number");
            s = num.readLine();
            a = Integer.parseInt(s);

            System.out.println("Enter the second number");
            s = num.readLine();
            b = Integer.parseInt(s);

            System.out.println("Enter the third number");
            s = num.readLine();
            c = Integer.parseInt(s);

            if (a > b && a > c) {
                max = a;
            } else if (b > c) {
                max = b;
            } else {
                max = c;
            }

            System.out.println("Maximum is " + max);
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}
