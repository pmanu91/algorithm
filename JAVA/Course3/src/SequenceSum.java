import java.util.Scanner;

public class SequenceSum {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		
		int[][] s = new int[n][n];
		int[] a = new int[n];
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				s[i][j] = scan.nextInt();
			}
		}
		
		a[0] = ( s[0][1] + s[0][2] - s[1][2] ) / 2;
		
		for (int i=1; i<n; i++) {
			a[i] = s[0][i] - a[0];
		}
		
		for (int i=0; i<n; i++) {
			System.out.print(a[i] + " ");
		}
		
	}
}
