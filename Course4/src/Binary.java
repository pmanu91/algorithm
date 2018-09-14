import java.util.Scanner;

public class Binary {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		
		int[] binary = {1,2,4,8,16,32,64,128,256,512};
		
		boolean flag = false;
		for (int i=0; i<10; i++) {
			if(n >= binary[9-i]) {
				n -= binary[9-i];
				flag = true;
				System.out.print(1);
			} else {
				if (flag)
					System.out.print(0);
			}
		}
		
	}
}
