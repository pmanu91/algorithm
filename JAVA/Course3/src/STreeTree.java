import java.util.Scanner;

public class STreeTree {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		
		int[] tree = new int[N];
		
		for (int i=0; i<N; i++) {
			tree[i] = scan.nextInt();
		}
		long gcd = tree[1]-tree[0];
		for (int i=2; i<N; i++) {
			gcd = getGcd(gcd, tree[i]-tree[i-1]);
		}
		
		int plantedTreeCount = 0;
		int position=tree[0];
		for(int i=1; i<N; ) {
			position+=gcd;
			if (position < tree[i]) {
				plantedTreeCount++;
			} else if (position >= tree[i]) {
				i++;
			}
		}
		
		System.out.println(plantedTreeCount);
	}
	
	public static long getGcd(long a, long b) {
		if (a < b) {
			long temp = a;
			a = b;
			b = temp;
		}
		if (a % b == 0) return b;
		else 
			return getGcd(b, a%b);
	}
}
