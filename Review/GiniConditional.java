import java.util.Scanner;

public class GiniConditional {
    public static void main(String[] args) {
        int year1, year2;
        double gini1, gini2, difference;
        String name, output;

        // Get country data from user
        Scanner stdin = new Scanner(System.in);
        System.out.print("Enter country name or 'done' to quit: ");
        name = stdin.nextLine();
        while (!name.equalsIgnoreCase("done")) {

            System.out.print("Enter first year: ");
            year1 = stdin.nextInt();
            System.out.print("Enter first year's Gini coefficient: ");
            gini1 = stdin.nextDouble();
            while (gini1 < 0 || gini1 > 1) {
                System.out.println("Gini coefficient must be between 0 and 1.");
                System.out.print("Enter first year's Gini coefficient: ");
                gini1 = stdin.nextDouble();
            }
            System.out.print("Enter second year: ");
            year2 = stdin.nextInt();
            System.out.print("Enter second year's Gini coefficient: ");
            gini2 = stdin.nextDouble();
            stdin.nextLine();

            // Calculate Gini coefficient difference
            difference = gini2 - gini1;

            // Print results
            if (difference > 0) {
                output = String.format("The Gini coefficient difference for %s ", name);
                output += String.format("between the years %d and %d ", year1, year2);
                output += String.format("increased by %.3f.", difference);
            }
            else if (difference < 0) {
                output = String.format("The Gini coefficient difference for %s ", name);
                output += String.format("between the years %d and %d ", year1, year2);
                output += String.format("decreased by %.3f.", difference);
            }
            else {
                output = String.format("The Gini coefficient difference for %s ", name);
                output += String.format("between the years %d and %d ", year1, year2);
                output += String.format("did not change.", difference);
            }
            System.out.println(output);
        }
    }
}