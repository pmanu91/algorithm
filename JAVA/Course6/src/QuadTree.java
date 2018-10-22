import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class QuadTree {
	static int n;
	static int img[][];
	static StringBuilder binSb = new StringBuilder();
	
	static String binaryToHex(String binary) {
		int decimal = Integer.parseInt(binary, 2);
		return Integer.toString(decimal, 16);
	}
	
	static void bfs() {
		Queue<Node> q = new LinkedList<>();

		q.offer(new Node(0, 0, 0));
		
		while(!q.isEmpty()) {
			Node fNode = q.poll();
			//System.out.println(fNode);
			if(n / (Math.pow(2, fNode.level)) < 1) return;
			
			int treeValue = checkImg(fNode.level, fNode);
			if (treeValue == -1) {
				binSb.append("1");
				
				int nextLevel = fNode.level + 1;
				int width = (int) (n / Math.pow(2, nextLevel));
				// 1 square
				q.offer(new Node(fNode.x, fNode.y, nextLevel));
				
				// 2 square
				q.offer(new Node(fNode.x+width, fNode.y, nextLevel));
				
				// 3 square
				q.offer(new Node(fNode.x, fNode.y+width, nextLevel));
				
				// 4 square
				q.offer(new Node(fNode.x+width, fNode.y+width, nextLevel));
			} else {
				binSb.append("0");
				binSb.append(treeValue);
			}
			
		}
	}
	
	static int checkImg(int level, Node node) {
		int p = img[node.y][node.x]; // compare initial data
		int width = (int) (n / Math.pow(2, level));
		for (int i=node.y; i<node.y + width; i++) {
			for (int j=node.x; j<node.x + width; j++) {
				if (p != img[i][j]) 
					return -1;
			}
		}
		
		return p;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		
		img = new int[n][n];
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				img[i][j] = scan.nextInt();
			}
		}
		
		bfs();
		System.out.println(binaryToHex(binSb.toString()).toUpperCase());
	}
	
	public static class Node {
		int x;
		int y;
		int level;
		public Node() { }
		public Node(int x, int y, int level) {
			this.x = x;
			this.y = y;
			this.level = level;
		}
		@Override
		public String toString() {
			return "Node [x=" + x + ", y=" + y + ", level=" + level + "]";
		}
		
		
	}
	
	
}
