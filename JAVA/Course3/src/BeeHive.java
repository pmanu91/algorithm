import java.util.Scanner;

public class BeeHive {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		
		int diff = 6;
		int num = 1;
		int layer = 0;
		for(int i=0; num<1000000; i+=diff) {
			num = num + i;
			layer++;
			if (N <= num) break;
		}
		System.out.println(layer);
	}
}
