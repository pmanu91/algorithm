import java.util.Scanner;
 
public class C2_MaxOfarr {
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int[][] matrix = new int[9][9];
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                matrix[i][j] = scan.nextInt();
            }
        }
        
        int max = 0;
        int x = 0, y = 0;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (matrix[i][j] > max) {
                	max = matrix[i][j];
                	x = j + 1;
                	y = i + 1;
                } else if (matrix[i][j] == max) {
                	if (i+1 < y) {
                		max = matrix[i][j];
                    	x = j + 1;
                    	y = i + 1;
                	} else if (i+1 == y) {
                		if (j+1 < x) {
                			max = matrix[i][j];
                        	x = j + 1;
                        	y = i + 1;
                		}
                	}
                }
            }
        }
        
        System.out.println(max);
        System.out.println(y + " " + x);
    }
}