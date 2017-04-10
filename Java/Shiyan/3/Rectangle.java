public class Rectangle {
    private double length, width;

    public Rectangle() {
        length = 1;
        width = 1;
    }

    public Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    public double Perimeter() {
        return (length + width) * 2.0;
    }

    public double Area() {
        return (length * width);
    }

    public static void main (String[] args) {
        Rectangle a = new Rectangle();
        Rectangle b = new Rectangle(2, 3);
        System.out.println(a.Perimeter() + " " + a.Area());
        System.out.println(b.Perimeter() + " " + b.Area());
    }
}
