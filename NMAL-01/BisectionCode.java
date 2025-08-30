import java.util.Scanner;

public class BisectionCode {


    static  double TOLERANCE ;


    public static double func(double x) {
        return (4*Math.pow(x, 2)) +(3* x) -3 ;
    }


    public static void bisection(double a, double b) {
        if (func(a) * func(b) >= 0) {
            System.out.println("the interval is not correct");
            return;
        }

        double c = a;
        double error = Math.abs(b - a);
        int iteration = 0;

        while (error >= TOLERANCE) {
            iteration++;
            c = (a + b) / 2;

            if (func(c) == 0.0)
                break;
            else if (func(c) * func(a) < 0)
                b = c;
            else
                a = c;

            error = Math.abs(b - a);
        }

        System.out.println("Approximate root is: " + c);
        System.out.println("Number of iterations: " + iteration);
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        System.out.print("Enter the value of a: ");
        double a = sc.nextDouble();

        System.out.print("Enter the value of b: ");
        double b = sc.nextDouble();

        System.out.print("Enter the value of tolerance: ");
        TOLERANCE = sc.nextDouble();
        bisection(a, b);
    }
}