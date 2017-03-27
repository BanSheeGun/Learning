public class s3 {

    public static int f(int n) {
        if (n == 1)
            return 1;
        else
            return (n + f(n-1));
    }

    public static void main (String[] args) {
        int a = f(100);
        System.out.println(a);
    }
}