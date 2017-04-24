class Point {
    private double x, y;

    public Point() {
        x = 0;
        y = 0;
        System.out.println("Point Created: " + this.toString());
    }

    public Point(double xx, double yy) {
        x = xx;
        y = yy;
        System.out.println("Point Created: " + this.toString());
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}

public class Circle extends Point {
    private double radius;

    public Circle() {
        super();
        radius = 1;
        System.out.println("Circle Created: " + this.toString());
    }

    public Circle(double xx, double yy, double rr) {
        super(xx, yy);
        radius = rr;
        System.out.println("Circle Created: " + this.toString());
    }

    public String toString() {
        return super.toString() + " r = " + radius;
    }

    public static void main(String[] args) {
        Point a = new Point();
        Point b = new Point(1, 1);
        Circle c = new Circle();
        Circle d = new Circle(1, 1, 2);
    }
}