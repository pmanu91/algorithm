import java.util.Scanner;


/**
 * 유클리드 호제법에 의해
 * 최대 공약수(gcd)는
 * A > B 일 때 A % B = r
 * gcd(A, B) = gcd(B, r) 과 동일함
 *
 * 최소 공배수(lcm)는
 * lcm * gcd = A * B
 * 곧, lcm = A * B / gcd(A, B)
 */
public class C1_GcdLcm {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();

        System.out.println(gcd(a, b));
        System.out.println(lcm(a,b));
    }

    public static int gcd(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (a % b == 0)
            return b;
        else
            return gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

}
