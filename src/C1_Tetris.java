import java.util.Scanner;

public class C1_Tetris {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int c = scan.nextInt();
        int r = scan.nextInt();

        int matrix[][] = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = scan.nextInt();
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
                        score = getClearScore(matrix, i, j, c, r);
                    } else {
                        if (i + 1 <= r) if (matrix[i+1][j] == 1) {
                            // j + 1 is block
                            score = getClearScore(matrix, i, j, c, r);
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

    public static int getClearScore(int[][] matrix, int i, int j, int c, int r) {
        int score = 0;
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
        return score;
    }

}
