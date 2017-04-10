import java.util.*;

public class InterRectangle {
    private double length, width;

    public InterRectangle() {
        this.length = 1;
        this.width = 1;
    }

    public InterRectangle(double l, double w) {
        this.length = l;
        this.width = w;
    }

    public double Perimeter() {
        return (this.length + this.width) * 2.0;
    }

    public double Area() {
        return (this.length * this.width);
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
