import java.util.Scanner;

public class Robot {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int TEST_CASE = scan.nextInt();
        for(int tc = 1; tc <= TEST_CASE; tc++) {
            int width = scan.nextInt();
            int height = scan.nextInt();
            int x = scan.nextInt();
            int y = scan.nextInt();

            // (1,1)부터 시작
            int[][] grid = new int[height+1][width+1];

            for (int i=1; i<=height; i++) {
                for(int j=1; j<=width; j++) {
                    grid[i][j] = scan.nextInt();
                }
            }

            int panelSize = scan.nextInt();
            int[] rotatePanel = new int[panelSize];

            for (int i=0; i<panelSize; i++) {
                rotatePanel[i] = scan.nextInt();
            }

            int commandSize = scan.nextInt();
            int score = grid[y][x];
            grid[y][x] = 0;
            //System.out.println("초기 점수: " + score);
            int rotatePostion = 0;
            for (int i=0; i<commandSize; i++) {
                String moveDirection = scan.next();
                int rotateDirection = scan.nextInt();
                int rotateCount = scan.nextInt();
                // 회전판 값을 가져옴

                int count = 0;
                while(++count<=rotateCount) {
                    if (rotateDirection == 1) {
                        // 시계방향
                        if (--rotatePostion < 0)
                            rotatePostion = rotatePanel.length - 1;
                    } else {
                        // 반시계방향
                        if (++rotatePostion > rotatePanel.length - 1)
                            rotatePostion = 0;
                    }
                }
                int moveDistance = rotatePanel[rotatePostion];
                //System.out.println(moveDirection+" 으로 " + moveDistance + " 칸 이동");
                // 로봇을 방향과 거리 만큼 이동
                int movedCount = 0;
                while (++movedCount<=moveDistance) {

                    // 방향으로 로봇 이동
                    // 가려는 방향으로 모서리나 장애물이 아니라면 이동하고 아니면 멈춤
                    if (moveDirection.equals("N")) {
                        if (y-1 >= 1 && grid[y-1][x] != -1){
                            y--;
                        } else {
                            //System.out.println("(" + x +", " + y +") 에서 멈춤");
                            break;
                        }
                    } else if (moveDirection.equals("E")) {
                        if (x+1 > width) break;
                        if (x+1 <= width && grid[y][x+1] != -1)
                            x++;
                        else {
                            //System.out.println("(" + x +", " + y +") 에서 멈춤");
                            break;
                        }
                    } else if (moveDirection.equals("S")) {
                        if (y+1 > height) break;
                        if (y+1 <= height && grid[y+1][x] != -1)
                            y++;
                        else {
                            //System.out.println("(" + x +", " + y +") 에서 멈춤");
                            break;
                        }
                    } else if (moveDirection.equals("W")) {
                        if (x-1 >= 1 && grid[y][x-1] != -1)
                            x--;
                        else {
                            //System.out.println("(" + x +", " + y +") 에서 멈춤");
                            break;
                        }
                    }

                    // 점수 가산 후 0으로 초기화
                    score += grid[y][x];
                    grid[y][x] = 0;
                    //System.out.println(x + "/" + y + "/score:" + score);
                }
            }
            System.out.println("#" + tc + " " + score + " " + x + " " + y);
        }
    }

}
