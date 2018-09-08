import java.util.Scanner;

public class C2_InOut2 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		
		int[][] matrix = new int[10][10];
		
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				matrix[i][j] = scan.nextInt();
			}
		}
		
		for (int m=0; m<n; m++) {
			// cross point change
			if (matrix[m][m] == 0) 
				matrix[m][m] = 1;
			else 
				matrix[m][m] = 0;
			
			// row change
			for (int i=0; i<10; i++) {
				for (int j=0; j<10; j++) {
					if (i == m) {
						if (j == m) {
							continue;
						} else {
							if (matrix[i][j] == 0)
								matrix[i][j] = 1;
							else
								matrix[i][j] = 0;
						}
					}
					
				}
			}
			
			// col change
			for (int i=0; i<10; i++) {
				for (int j=0; j<10; j++) {
					if (j == m) {
						if (i == m) {
							continue;
						} else {
							if (matrix[i][j] == 0)
								matrix[i][j] = 1;
							else
								matrix[i][j] = 0;
						}
					}
				}
			}
		
		}
		
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}
}
