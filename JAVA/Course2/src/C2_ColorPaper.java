import java.util.Scanner;

public class C2_ColorPaper {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		
		int[][] matrix = new int[101][101];
		int[] totalArea = new int[N];
		
		for (int num=1; num<=N; num++) {
		
			int x = scan.nextInt();
			int y = scan.nextInt();
			int width = scan.nextInt();
			int height = scan.nextInt();
			
			
			for (int i=0; i<101; i++) {
				for (int j=0; j<101; j++) {
					if (i >= x && i <= x+width-1 && j >= y && j <= y+height-1) {
						matrix[i][j] = num;
					}
				}
			}
			
		}
		
		for (int num=1; num<=N; num++) {
			for (int i=0; i<101; i++) {
				for (int j=0; j<101; j++) {
					if (matrix[i][j] == num) 
						totalArea[num-1]++;
				}
			}
			System.out.println(totalArea[num-1]);
		}
		
		
	}

}
