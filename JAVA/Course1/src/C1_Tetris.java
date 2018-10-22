import java.util.Scanner;
 
public class C1_Tetris {
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
 
        int c = scan.nextInt();
        int r = scan.nextInt();
 
        int matrix[][] = new int[r][c];
        int subMatrix[][] = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = scan.nextInt();
                subMatrix[i][j] = matrix[i][j];
            }
        }
 
 
        int x = 0;
        int y = 0;
        for (int i = r - 1; i >= 3; i--) {
            for (int j = 0; j < c ; j++) {
                // enable stick
                if(matrix[i][j] == 0 && matrix[i-1][j] == 0 && matrix[i-2][j] == 0 && matrix[i-3][j] == 0) {
                    int score = 0;
                    // j + 1 is floor
                    if (i + 1 == r) {
                        matrix[i][j] = 1; matrix[i-1][j] = 1; matrix[i-2][j] = 1; matrix[i-3][j] = 1;
                        for (int m = 0; m < c; m++) {
                            boolean isClear = true;
 
                            for (int n = 0; n < r; n++) {
                                if (matrix[m][n] == 0) {
                                    isClear = false;
                                    break;
                                }
                            }
                            if (isClear) {
                                score++;
                            }
                        }
                        matrix[i][j] = 0; matrix[i-1][j] = 0; matrix[i-2][j] = 0; matrix[i-3][j] = 0;
                    } else {
                        if (i + 1 <= r) if (matrix[i+1][j] == 1) {
                            // j + 1 is block
                            matrix[i][j] = 1; matrix[i-1][j] = 1; matrix[i-2][j] = 1; matrix[i-3][j] = 1;
                            for (int m = 0; m < r; m++) {
                                boolean isClear = true;
 
                                for (int n = 0; n < c; n++) {
                                    if (matrix[m][n] == 0) {
                                        isClear = false;
                                        break;
                                    }
                                }
                                if (isClear) {
                                    score++;
                                }
                            }
                            matrix[i][j] = 0; matrix[i-1][j] = 0; matrix[i-2][j] = 0; matrix[i-3][j] = 0;
                        }
                    }
                    if (score > y) {
                        y = score;
                        x = j + 1;
                    }
                }
            }
        }
 
        System.out.println(x + " " + y);
 
    }
 
}