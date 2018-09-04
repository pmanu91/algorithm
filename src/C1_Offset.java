import java.util.Scanner;

public class C1_Offset {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int[][] matrix = new int[5][5];
        int[][] chkMatrix = new int[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = scan.nextInt();
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                boolean check = true;

                if (j + 1 < 5) if (matrix[i][j] >= matrix[i][j + 1]) check = false;
                if (j - 1 >= 0) if (matrix[i][j] >= matrix[i][j - 1]) check = false;
                if (i + 1 < 5) if (matrix[i][j] >= matrix[i + 1][j]) check = false;
                if (i - 1 >= 0) if (matrix[i][j] >= matrix[i - 1][j]) check = false;

                if (check == true)
                    chkMatrix[i][j] = -1;
                else
                    chkMatrix[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (chkMatrix[i][j] == -1)
                    System.out.print("* ");
                else
                    System.out.print(chkMatrix[i][j] + " ");
            }
            System.out.println();
        }

    }
}
