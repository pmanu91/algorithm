import java.util.Scanner;

public class Chebyshevtheo {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

//		int[] numberOfPrime = new int[123456*2+1];
//		
//		numberOfPrime[1] = 1;
//		numberOfPrime[2] = 2;
//		for (int i=3; i<=123456*2; i++) {
//			boolean isPrime = true;
//			for (int j=2; j<i; j++) {
//				if (i%j == 0) {
//					isPrime = false;
//					break;
//				}
//			}
//			if (isPrime) {
//				numberOfPrime[i] = numberOfPrime[i-1] + 1;
//			} else {
//				numberOfPrime[i] = numberOfPrime[i-1];
//			}
//		}
//		
//		int n;
//		while((n = scan.nextInt()) != 0) {
//			int csCount = numberOfPrime[2*n] - numberOfPrime[n];
//			System.out.println(csCount);
//		}
		
		
		int n;
		while((n = scan.nextInt()) != 0) {
			int primeCount=0;
			if (n == 1) {
				System.out.println(1);
				continue;
			}
			for (int i=n+1; i<=2*n; i++) {
				// i is prime?
				boolean isPrime = true;
				for (int k=2; k*k<=i; k++) {
					if (i%k == 0) {
						isPrime = false;
						break;
					}
				}
				if (isPrime) {
					primeCount++;
				}
			}
			System.out.println(primeCount);
		}
	}
}
