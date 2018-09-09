import java.util.Scanner;

public class NextNum {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		while(true) {
			int a1 = scan.nextInt();
			int a2 = scan.nextInt();
			int a3 = scan.nextInt();
			
			if (a1 == 0 && a2 == 0 && a3 == 0) return;
			
			String xx = "";
			int y=0;
			int nextNum=0;
			if ((a2-a1) == (a3-a2)) {
				// AP
				xx = "AP";
				y = a2 - a1;
				nextNum = a3 + y;
			} else {
				// GP
				xx = "GP";
				y = a2 / a1;
				nextNum = a3 * y;
			}
			
			System.out.println(xx + " " + nextNum);
		}
		
	}
}
