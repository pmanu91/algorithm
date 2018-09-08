import java.util.Scanner;
 
public class C1_Seat {
    
    public static int N = 1;
    public static int E = 2;
    public static int S = 3;
    public static int W = 4;
    
 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int c = scan.nextInt();
        int r = scan.nextInt();
        int k = scan.nextInt();
        
        int seats[][] = new int[c+1][r+1];
        
        // cannot seat
        if (k > c * r) {
            System.out.println(0);
            return;
        }
        
        int num = 1;
        int x=1;
        int y=1;
        int direction = N;
        for(int i = 1; i < c*r + 1; i++) {
            // apply seat
            seats[x][y] = num++;
            // select next seat
            if (direction == N) {
                // change direction ( edgy or already direction)
                if (y+1 > r) {
                    direction = E;
                    x++;
                } else {
                    if (seats[x][y+1] != 0) {
                        direction = E;
                        x++;
                    } else {
                        y++;
                    }
                }
            } else if (direction == E) {
                if (x+1 > c) {
                    direction = S;
                    y--;
                } else {
                    if (seats[x+1][y] != 0) {
                        direction = S;
                        y--;
                    } else {
                        x++;
                    }
                }
            } else if (direction == S) {
                if (y-1 < 1) {
                    direction = W;
                    x--;
                } else {
                    if (seats[x][y-1] != 0) {
                        direction = W;
                        x--;
                    } else {
                        y--;
                    }
                }
            } else if (direction == W) {
                if (x-1 < 1) {
                    direction = N;
                    y++;
                } else {
                    if (seats[x-1][y] != 0) {
                        direction = N;
                        y++;
                    } else {
                        x--;
                    }
                }
            }
            
            // in case, k = num
            if (k == num) {
                System.out.println(x + " " + y);
                return;
            }
        }
    }
}