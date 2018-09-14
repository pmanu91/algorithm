import java.util.Scanner;

public class PFactorization {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		
		int number = 2;
		while(n > 1) {
			if( n % number == 0) {
				n /= number;
				System.out.println(number); 
			} else {
				number++;
			}
		}
	}
}
