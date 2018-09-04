import java.util.Scanner;

public class C1_Car {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int day = sc.nextInt();
        int[] cars = new int[5];
        int violatedCars = 0;

        for (int i = 0; i < 5; i++) {
            cars[i] = sc.nextInt();
        }

        for (int i = 0; i < 5; i++) {
            if (cars[i] == day) violatedCars++;
        }

        System.out.print(violatedCars);

    }
}
