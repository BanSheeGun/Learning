import java.util.*;

public class s2 {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = a / 10 - 4;
        if (b > 5 || b < 2)
            b = 1;
        if (a == 100)
            b = 5;
        System.out.println(b);
    }
}