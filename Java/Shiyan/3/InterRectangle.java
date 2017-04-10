import java.util.*;

public class InterRectangle {
    private double length, width;

    public InterRectangle() {
        length = 1;
        width = 1;
    }

    public InterRectangle(double l, double w) {
        length = l;
        width = w;
    }

    public double Perimeter() {
        return (length + width) * 2.0;
    }

    public double Area() {
        return (length * width);
    }

    public static double TotalPerimeter, TotalArea;

    public static void main (String[] args) {
        InterRectangle[] a;
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        a = new InterRectangle [n];

        for (int i = 0; i < n; ++i) {
            double x, y;
            x = scan.nextDouble();
            y = scan.nextDouble();
            a[i] = new InterRectangle(x, y);
            TotalArea += a[i].Area();
            TotalPerimeter += a[i].Perimeter();
        }

        System.out.println(TotalPerimeter + " " + TotalArea);
    }
}
