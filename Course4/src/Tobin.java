import java.util.Scanner;

public class Tobin {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		int k = scan.nextInt();
		
		
	}
	
	public static void printBinary(int n, int k) {
		if (n==k) {
			return;
		}
		printBinary(n-1, k);
	}
}
