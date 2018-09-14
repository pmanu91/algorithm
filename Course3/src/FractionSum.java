import java.util.Scanner;

public class FractionSum {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int a1 = scan.nextInt();
		int a2 = scan.nextInt();
		
		int b1 = scan.nextInt();
		int b2 = scan.nextInt();
		
		int fractionSum1 = (a1*b2) + (b1*a2);
		int fractionSum2 = a2 * b2;
		
		int fractionGcd = getGcd(fractionSum1, fractionSum2);
		fractionSum1 /= fractionGcd;
		fractionSum2 /= fractionGcd;
		
		System.out.println(fractionSum1 + " " + fractionSum2);
	}
	
	public static int getGcd(int a, int b) {
		if (a<b) {
			int temp = a;
			a=b;
			b=temp;
		}
		if (a%b == 0) return b;
		else 
			return getGcd(b, a%b);
	}
}
