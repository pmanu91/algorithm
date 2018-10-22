import java.util.Scanner;

import javax.script.ScriptException;

public class P1_SecretMap {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		int arr1[] = new int[n];
		int arr2[] = new int[n];
		
		String map1[] = new String[n];
		String map2[] = new String[n];
		String secretMap[] = new String[n];
		
		// input arr1
		for (int i=0; i<n; i++)
			arr1[i] = scan.nextInt();

		// input arr2
		for (int i=0; i<n; i++)
			arr2[i] = scan.nextInt();
		
		changeDecimalToBinaryMap(arr1, map1);
		changeDecimalToBinaryMap(arr2, map2);
		
		for (int i=0; i<n; i++) {
			secretMap[i] = "";
			for (int j=0; j<n; j++) {
				if (map1[i].charAt(j) == '1' || map2[i].charAt(j) == '1') {
					secretMap[i] += "#";
				} else {
					secretMap[i] += " ";					
				}
			}
		}
		
		for (int i=0; i<n; i++) {
			System.out.println(secretMap[i]);
		}
		
 	}
	
	public static void changeDecimalToBinaryMap(int[] arr, String[] map) {
		for (int i=0; i<arr.length; i++) {
			StringBuffer sb = decimalToBinary(arr[i], new StringBuffer());
			map[i] = sb.toString();
		}
		for (int i=0; i<arr.length; i++) {
			if (map[i].length() <= arr.length) {
				String zero = "";
				for (int j=0; j<arr.length-map[i].length(); j++) {
					zero += "0";
				}
				map[i] = zero + map[i];
			}
		}
	}
	
	public static StringBuffer decimalToBinary(int num, StringBuffer sb) {
		if(num < 2) 
			return sb.append(num);
		else {
			decimalToBinary(num/2, sb);
			return sb.append(num%2);			
		}
	}
	
	
}
