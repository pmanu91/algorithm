import java.util.Scanner;
 
public class C1_Bingo {
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int[][] userBingo = new int[5][5];
        int[] mcNum = new int[25];
        
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                userBingo[i][j] = scan.nextInt();
            }
        }
        
        for(int i=1; i<=25; i++) {
            mcNum[i-1] = scan.nextInt();
        }
        
        for(int count=1; count<=25; count++) {
            int score=0;
            int num = mcNum[count-1];
            
            // user check
            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    if (userBingo[i][j] == num) userBingo[i][j] = 0;
                }
            }
            
            // parallel bingo
            for (int i=0; i<5; i++) {
                boolean bingo = true;
                for (int j=0; j<5; j++) {
                    if (userBingo[i][j] != 0) {
                        bingo = false;
                        break;
                    }
                }
                if (bingo) {
                    score++;
                }
            }
            
            // vertical bingo
            for (int j=0; j<5; j++) {
                boolean bingo = true;
                for (int i=0; i<5; i++) {
                    if (userBingo[i][j] != 0) {
                        bingo = false;
                        break;
                    }
                }
                if (bingo) {
                    score++;
                }
            }
            
            // diagonal bingo
            // 1.
            boolean d1Bingo = true;
            for (int d=0; d<5; d++) {
                if (userBingo[d][d] != 0) {
                    d1Bingo = false;
                    break;
                }
            }
            if (d1Bingo) {
                score++;
            }
            
            // 2.
            boolean d2Bingo = true;
            for (int d=0; d<5; d++) {
                if (userBingo[4-d][d] != 0) {
                    d2Bingo = false;
                    break;
                }
            }
            if (d2Bingo) {
                score++;
            }
            
            
            // bingo score = 3
            
            if (score >= 3) {
                System.out.println(count);
                break;
            }
        }
        
        
        
        
    }
}