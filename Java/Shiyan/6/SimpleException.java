public class SimpleException {
    public static double Division(double x, double y) {
        if (y == 0)
            throw new IllegalArgumentException("y can't be 0");
        return x / y;
    }

    public static void main(String[] args) {
        try {
            double a = Double.parseDouble(args[0]);
            double b = Double.parseDouble(args[1]);
            System.out.println(Division(a, b));
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Need args");
        } catch (NumberFormatException e) {
            System.out.println("Need two double");
        } catch (IllegalArgumentException IAE) {
            System.out.println(IAE.toString());
        } catch (Exception e) {
            System.out.println(e.toString());
        } finally {
            System.out.println("Game is over!");
        }
    }
}