import java.util.Scanner;
import java.util.StringTokenizer;

public class Main1 {

	public static void main(String... args) {
		String input = new Scanner(System.in).nextLine().trim();
		final StringTokenizer tokenizer = new StringTokenizer(input);

		int money = 20000;

		while (tokenizer.hasMoreTokens()) {
			int distance = Integer.parseInt(tokenizer.nextToken());

			if (distance < 4 || distance > 178) {
				System.out.println(money);
				return;
			}

			int fee;
			if (distance > 40) {
				int plusDistance = distance - 40;
				int plusFee = 0;
				if(plusDistance % 8 != 0) {
					plusFee = 1;
				}
				
				fee = 720 + ((plusDistance / 8 + plusFee) * 80);
			} else {
				fee = 720;
			}

			if (money - fee < 0) {
				System.out.println(money);
				return;
			} else {
				money -= fee;
			}
		}

		System.out.println(money);

	}
}