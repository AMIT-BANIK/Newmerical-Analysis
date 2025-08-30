import java.util.Scanner;

public class Task2Bisection {
    static  double TOLERANCE ;


    public static double f(double x) {
        return (4*Math.pow(x, 2)) +(3* x) -3 ;
    }


    public static void bisection(double a, double b) {
        if (f(a) * f(b) >= 0) {
            System.out.println("the interval is not correct");
            return;
        }

        double c = a;
        double error = Math.abs(b - a);
        int iteration = 0;

        while (error >= TOLERANCE) {
            iteration++;
            c = (a + b) / 2;

            if (f(c) == 0.0)
                break;
            else if (f(c) * f(a) < 0)
                b = c;
            else
                a = c;

            error = Math.abs(b - a);
        }

        System.out.println("Approximate root is in Bisection: " + c);
        System.out.println("Number of iterations needed in Bisection Method: " + iteration);
    }
    public static void FalsePosition(double a,double b){
        int iterations = 0;

        if (f(a) * f(b) > 0) {
            System.out.println("Invalid interval");
            return;
        }
        double Ea=Math.abs(a-b);
        double c=a;

        while (Ea >=Math.abs(TOLERANCE) ) {
            c = b - ((f(b) * (a - b)) / (f(a) - f(b)));

            if (Math.abs(f(c)) <=TOLERANCE)
                break;

            if (f(a) * f(c) < 0)
                b = c;
            else
                a = c;

            iterations++;
            Ea=Math.abs(a-b);
        }
        System.out.println("Approximate Root in False = " + c);
        System.out.println("Total Iterations needed in False Method = " + (iterations + 1));
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
        FalsePosition(a,b);
    }
}
//[0,1].0.05
