import java.util.Scanner;
 
public class C1_Baseball {
 
    public static void main(String[] args) {
 
        Scanner scan = new Scanner(System.in);
 
        int n = scan.nextInt();
        int[][] baseball = new int[n][3];
 
        for (int i = 0; i < n; i++) {
            // num
            baseball[i][0] = scan.nextInt();
            // strike
            baseball[i][1] = scan.nextInt();
            // ball
            baseball[i][2] = scan.nextInt();
        }
 
        int passCount = 0;
        for (int i = 1; i <= 9; i++) {
            // 100
            for (int j = 1; j <= 9; j++) {
                // 10
                if (j == i)    continue;
 
                for (int k = 1; k <= 9; k++) {
                    // 1
                    if (k == i || k == j) continue;
                    boolean isPassCase = true;
                    for (int t = 0; t < n; t++) {
                        int num = baseball[t][0];
                        int num100 = num / 100;
                        int num10 = (num % 100) / 10;
                        int num1 = (num % 10);
                        int strike = 0;
                        int ball = 0;
 
                        // 100 compare
                        if (num100 == i) strike++;
                        if (num10 == i || num1 == i) ball++;
                        
                        // 10 compare
                        if (num10 == j) strike++;
                        if (num100 == j || num1 == j) ball++;
                        
                        // 1 compare
                        if (num1 == k) strike++;
                        if (num100 == k || num10 == k) ball++;
                        
                        if (strike != baseball[t][1] || ball != baseball[t][2]) {
                            isPassCase = false;
                            break;
                        }
                    }
                    if (isPassCase) passCount++;
                }
            }
        }
        System.out.println(passCount);
        
    }
}