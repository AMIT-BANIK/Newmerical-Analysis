import java.util.Scanner;

public class FalsePositionMethodCode {
    public static double f(double x) {
        return Math.log(3 * x) - 3;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the value of a: ");
        double a = sc.nextDouble();

        System.out.print("Enter the value of b: ");
        double b = sc.nextDouble();

        System.out.print("Enter the value of Es: ");
        double Es = sc.nextDouble();

        int iterations = 0;

        if (f(a) * f(b) > 0) {
            System.out.println("Invalid interval");
            return;
        }
        double Ea=Math.abs(a-b);
        double c=a;

        while (Ea >=Math.abs(Es) ) {
             c = b - ((f(b) * (a - b)) / (f(a) - f(b)));

            if (Math.abs(f(c)) <=Es)
                break;

            if (f(a) * f(c) < 0)
                b = c;
            else
                a = c;

            iterations++;
            Ea=Math.abs(a-b);
        }
        System.out.println("Approximate Root = " + c);
        System.out.println("Total Iterations = " + (iterations + 1));
    }

}
