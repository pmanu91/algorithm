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
		
		
	}
}
