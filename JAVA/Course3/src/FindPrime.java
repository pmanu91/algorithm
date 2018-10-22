import java.util.Scanner;

public class FindPrime {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		int[] arr = new int[n];
		
		int count=0;
		for(int i=0; i<n; i++) {
			arr[i] = scan.nextInt();
			
		}
		
		for (int i=0; i<n; i++) {
			if (arr[i] == 1) continue;
			boolean isPrime = true;
			for (int k=2; k<arr[i]; k++) {
				if(arr[i]%k == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) count++;
		}
		
		System.out.println(count);
	}
}
