import java.util.Scanner;

public class C2_Rook {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int matrix[][] = new int[8][8];
		
		int kingX = -1;
		int kingY = -1;
		
		int rookX = -1;
		int rookY = -1;
		
		for (int i=0; i<8; i++) {
			for (int j=0; j<8; j++) {
				matrix[i][j] = scan.nextInt();
				if (matrix[i][j] == 1) {
					kingX = j;
					kingY = i;
				} else if (matrix[i][j] == 2) {
					rookX = j;
					rookY = i;
				}
			}
		}
		
//		System.out.println("king : " + kingX + " / " + kingY);
//		System.out.println("rook : " + rookX + " / " + rookY);
//		
		if (kingX == rookX || kingY == rookY) {
			// death enable
			if (kingX == rookX) {
				int largeY=-1;
				int smallY=-1;
				
				if (kingY > rookY) {
					largeY = kingY; smallY = rookY;
				} else {
					largeY = rookY; smallY = kingY;
				}
				
				// check barrier between king and rook
				for (int i=smallY+1; i<largeY; i++) {
					if (matrix[i][kingX] == 3) {
						// alive
						System.out.println(0);
						return;
					}
				}
			}
			
			if (kingY == rookY) {
				int largeX=-1;
				int smallX=-1;
				
				if (kingX > rookX) {
					largeX = kingX; smallX = rookX;
				} else {
					largeX = rookX; smallX = kingX;
				}
				
				// check barrier between king and rook
				for (int j=smallX+1; j<largeX; j++) {
					if (matrix[kingY][j] == 3) {
						// alive
						System.out.println(0);
						return;
					}
				}
			}
			
			// death
			System.out.println(1);
		} else {
			// death disable
			System.out.println(0);
		}
		
	}
}
