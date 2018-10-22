import java.util.Scanner;

public class C2_AttackRange {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		int unitY = scan.nextInt();
		int unitX = scan.nextInt();
		int attackRange = scan.nextInt();
		
		String[][] matrix = new String[n][n];
		
		// matrix initialize
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
					matrix[i][j] = "0";
			}
		}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				// position of unit
				if (unitX-1 == j && unitY-1 == i) {
					matrix[i][j] = "x";
				}
				for (int r=1; r<=attackRange; r++) {
					if ( Math.abs((j+1)-unitX) + Math.abs((i+1)-unitY) == r ) {
						matrix[i][j] = r + "";
					}
						
				}
			}
		}
		 
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
					System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}
}
