import java.util.Scanner;

public class C2_Mine {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt(); // row
		int M = scan.nextInt(); // col
		
		int X = scan.nextInt(); // click row
		int Y = scan.nextInt(); // click col
		
		int[][] matrix = new int[N+1][M+1];
		
		for (int i=1; i<N+1; i++) {
			for (int j=1; j<M+1; j++) {
				matrix[i][j] = scan.nextInt();
			}
		}
		
		// game over
		if (matrix[X][Y] == 1) {
			System.out.println("game over");
			return;
		}
		
		int mineCount = 0;
		for (int i=X-1; i<=X+1; i++) {
			// out of map
			if (i < 1 || i > N)	
				continue;
			
			for (int j=Y-1; j<=Y+1; j++) {
				// out of map
				if (j < 1 || j > M) 
					continue;
				
				if (matrix[i][j] == 1) {
					mineCount++;
				}
			}
		}
		
		System.out.println(mineCount);
	}
}
