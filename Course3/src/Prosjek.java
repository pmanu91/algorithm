import java.util.Scanner;

public class Prosjek {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		
		int[] b = new int[n];
		int[] a = new int[n];
		
		for (int i=0; i<n; i++) {
			b[i] = scan.nextInt();
		}
		
		// first element is equal
		a[0] = b[0];
		
		for (int i=1; i<n; i++) {
			int sum = 0;
			for (int j=0; j<i; j++) {
				sum += a[j];
			}
			a[i] = (i+1) * b[i] - sum;
		}
		
		for (int i=0; i<n; i++) {
			System.out.print(a[i] + " ");
		}
		
		
	}
}