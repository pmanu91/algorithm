import java.util.Scanner;

public class FmttAlpha {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int x = scan.nextInt();
		int y = scan.nextInt();
		
		int distance = y-x;
		
		int[] maxDistancePerCount = new int[100000];
		
		if (distance == 1) {
			System.out.println(1);
			return;
		}
		
		maxDistancePerCount[1] = 1;
		int k = 1;
		for (int i=2; i<100000; i++) {
			if (i%2 == 0) {
				maxDistancePerCount[i] = maxDistancePerCount[i-1] + k;
			} else {
				maxDistancePerCount[i] = maxDistancePerCount[i-1] + (++k);
			}
			
			if (distance <= maxDistancePerCount[i]) {
				System.out.println(i);
				break;
			}
		}
	}
}
