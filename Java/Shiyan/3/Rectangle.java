public class Rectangle {
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

    public static void main (String[] args) {
        Rectangle a = new Rectangle();
        Rectangle b = new Rectangle(2, 3);
        System.out.println(a.Perimeter() + " " + a.Area());
        System.out.println(b.Perimeter() + " " + b.Area());
    }
}
