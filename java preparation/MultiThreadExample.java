import java.util.Random;

class RandomNumberGenerator implements Runnable {
    private Random random = new Random();

    @Override
    public void run() {
        try {
            while (true) {
                int randomNumber = random.nextInt(100); // Generate random integer between 0 and 99
                System.out.println("Generated: " + randomNumber);

                if (randomNumber % 2 == 0) {
                    // Number is even, create and start a SquareThread
                    SquareThread squareThread = new SquareThread(randomNumber);
                    Thread thread = new Thread(squareThread);
                    thread.start();
                } else {
                    // Number is odd, create and start a CubeThread
                    CubeThread cubeThread = new CubeThread(randomNumber);
                    Thread thread = new Thread(cubeThread);
                    thread.start();
                }

                Thread.sleep(1000); // Sleep for 1 second
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class SquareThread implements Runnable {
    private int number;

    public SquareThread(int number) {
        this.number = number;
    }

    @Override
    public void run() {
        int square = number * number;
        System.out.println("Square of " + number + " is: " + square);
    }
}

class CubeThread implements Runnable {
    private int number;

    public CubeThread(int number) {
        this.number = number;
    }

    @Override
    public void run() {
        int cube = number * number * number;
        System.out.println("Cube of " + number + " is: " + cube);
    }
}

public class MultiThreadExample {
    public static void main(String[] args) {
        // Create and start the RandomNumberGenerator thread
        Thread randomNumberGeneratorThread = new Thread(new RandomNumberGenerator());
        randomNumberGeneratorThread.start();
    }
}