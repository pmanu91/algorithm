import java.util.Scanner;

public class Lcm {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		long a = scan.nextInt();
		long b = scan.nextInt();
		
		System.out.println(getLcm(a,b));
	}
	
	public static long getGcd(long a, long b) {
		// gcd(a,b) = gcd(b,r)
		if (b > a) {
			long temp = a;
			a = b;
			b = temp;
		}
		if (a%b == 0) return b;
		else 
		return getGcd(b, a%b);
	}
	
	public static long getLcm(long a, long b) {
		// lcm = a * b / gcd
		return a * b / getGcd(a, b);
	}

}
