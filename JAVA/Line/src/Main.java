import java.util.Scanner;


// 5
// F1 B1 R1 L2 F1
// F1 L2 L1 L2 F1
// F1 B1 B1 L2 F1
// F1 L2 R1 L2 F1
// L3 L1 B2 L3 B1
public class Main {
	
	static final int N = 0;
	static final int E = 1;
	static final int S = 2;
	static final int W = 3;
	
	static final int FORWARD = 0;
	static final int RIGHT = 1;
	static final int BACKWARD = 2;
	static final int LEFT = 3;
	
	// 이전 FOWARD 이면 현재방향 + 0;
	// 이전 RIGHT 이면 (현재방향 + 1) % 4;
	// 이전 LEFT 이면 (현재방향 + 3) % 4;
	// 이전 BACKWARD 이면 (현재방향 + 2) % 4;
	
	// 방문한 곳을 다시 방문했을 때 보물
	
	static String matrix[][];
	static boolean visited[][];
	static int n;

	
    public static void main(String[] args) {
    	
    	Scanner scan = new Scanner(System.in);
    	n = scan.nextInt();
    	matrix = new String[n][n];
    	visited = new boolean[n][n];
    	for (int i=0; i<n; i++) {
    		for (int j = 0; j<n; j++) {
    			matrix[i][j] = scan.next();
    		}
    	}
    	
    	move(S, 0, 0);
    }
    
	public static void move(int nowDirection, int x, int y) {
		String direction = matrix[y][x].substring(0, 0);
		int distance = Integer.parseInt(matrix[y][x].substring(1, 1));
		
		int nextDirection = -1;
		switch(direction) {
		case "F" :
			nextDirection = nowDirection;
			break;
		case "R" :
			nextDirection = (nowDirection + 1) % 4;
			break;
		case "B" :
			nextDirection = (nowDirection + 2) % 4;
			break;
		case "L" :
			nextDirection = (nowDirection + 3) % 4;
			break;
		}
		
		switch(nextDirection) {
		case N:
			
			break;
		case E:
			break;
		case S:
			break;
		case W:
			break;
		}
	}
    
    
}