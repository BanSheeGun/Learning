public class s2 {
    public static void main(String[] args) {
        int[] a;
        a = new int [21];
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i <= 20; ++i)
            a[i] = a[i-1] + a[i-2];

        for (int i = 0; i <= 20; ++i)
            System.out.println("F[" + i + "]=" + a[i]);
    }
}