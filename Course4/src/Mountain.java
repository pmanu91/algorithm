import java.util.Scanner;

public class Mountain {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int num = scan.nextInt();
		StringBuilder sb = drawMountain(num, new StringBuilder());
		System.out.println(sb.toString());
	}
	
	public static StringBuilder drawMountain(int num, StringBuilder sb) {
		if(num == 1) {
			return sb.append(1);
		}
		sb.append(drawMountain(num-1, new StringBuilder()));
		sb.append(num);
		sb.append(drawMountain(num-1, new StringBuilder()));
		return sb;
	}
	
}
