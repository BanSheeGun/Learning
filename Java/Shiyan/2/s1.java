import java.lang.Math;

public class s1 {
    public static void main (String[] args) {
        int ma = 0, mi = 99, sum = 0;
        for (int i = 1; i <= 100; ++i) {
            int k = (int)Math.floor(java.lang.Math.random() * 100);
            ma = java.lang.Math.max(ma, k);
            mi = java.lang.Math.min(mi, k);
            if (k > 50)
                ++sum;
        }
        System.out.println(ma + " " + mi + " " + sum);
    }
}