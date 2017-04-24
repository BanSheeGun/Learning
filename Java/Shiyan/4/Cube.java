public class Cube extends Rectangle {

    public Cube() {
        super();
    }

    public Cube(double a) {
        super(a, a);
    }

    public double GetCube() {
        return super.Area() * super.GetLength();
    }

    public static void main (String[] args) {
        Cube a = new Cube();
        Cube b = new Cube(2);
        System.out.println(a.Perimeter() + " " + a.Area() + " " + a.GetCube());
        System.out.println(b.Perimeter() + " " + b.Area() + " " + b.GetCube());
    }
}
