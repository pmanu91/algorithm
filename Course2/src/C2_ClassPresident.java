import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class C2_ClassPresident {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		int[][] studentBan = new int[N][5];
		
		ArrayList<HashSet<Integer>> studentList = new ArrayList<>();
		for (int i=0; i<N; i++) {
			HashSet<Integer> friendSet = new HashSet<>();
			studentList.add(friendSet);
			for (int j=0; j<5; j++) {
				studentBan[i][j] = scan.nextInt();
			}
		}
		
		
		for (int i=0; i<5; i++) {
			for (int j=0; j<N; j++) {
				for (int k=0; k<N; k++) {
					if (k == j) continue;
					if(studentBan[j][i] == studentBan[k][i]) {
						studentList.get(j).add(k);
					}
				}
			}
		}
		
		int classPresident=-1;
		int maxFriend=-100;
		for (int i=0; i<N; i++) {
			if (studentList.get(i).size() > maxFriend) {
				classPresident = i+1;
				maxFriend = studentList.get(i).size();
			} else if (studentList.get(i).size() == maxFriend) {
				if (i+1 < classPresident) {
					classPresident = i+1;
					maxFriend = studentList.get(i).size();
				} else {
					continue;
				}
			}
		}
		
		System.out.println(classPresident);
	}
}
