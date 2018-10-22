import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Dart {

	static int[] roundScore = new int[3];
	public static void main(String[] args) {
		
		run("1S2D*3T");
		run("1D2S#10S");
		run("1D2S0T");
		run("1S*2T*3S");
		run("1D#2S*3S");
		run("1T2D3D#");
		run("1D2S3T*");
		
	}
	
	public static void run(String msg) {
		String regex = "(\\d{1,2}[S|D|T][*|#]{0,1})";
		Pattern p = Pattern.compile(regex+regex+regex);
		Matcher m = p.matcher(msg);
		m.find();
		
		for (int i=0; i<3; i++) {
			String round = m.group(i+1);
			Pattern p1 = Pattern.compile("(\\d{1,2})([S|D|T])([*|#]{0,1})");
			Matcher m1 = p1.matcher(round);
			m1.find();
			
			int score = Integer.parseInt(m1.group(1));
			String bonusType = m1.group(2);
			String option = m1.group(3);
			
			roundScore[i] = calBonus(score, bonusType);
			setOption(i, option);
		}
		
		System.out.println("msg : " + msg + " - " + (roundScore[0] + roundScore[1] + roundScore[2]));
	}
	
	public static void setOption(int idx, String option) {
		if (option.equals("*")) {
			roundScore[idx] *= 2;
			if (idx > 0) {
				roundScore[idx-1] *= 2;
			}
		} else if (option.equals("#")) {
			roundScore[idx] *= -1;
		}
	}
	
	public static int calBonus(int score, String bonusType) {
		int calScore = 0;
		if (bonusType.equals("S")) {
			calScore = score;
		} else if (bonusType.equals("D")) {
			calScore = score * score;
		} else if (bonusType.equals("T")) {
			calScore = score * score * score;
		}
		return calScore;
	}
}
