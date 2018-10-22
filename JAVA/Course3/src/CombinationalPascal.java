import java.util.Scanner;

public class CombinationalPascal {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		long n = scan.nextInt();
		long m = scan.nextInt();
		
		// nCm = n! / (m!*(n-m)!)
		System.out.println(ncm(n, m));
	}
	
	public static long ncm(long n, long m) {
		if (n==m) return 1;
		else
		return ncm(n-1, m) * n / (n-m);
	}
}
