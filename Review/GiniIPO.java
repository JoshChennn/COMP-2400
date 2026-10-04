import java.util.Scanner;

public class GiniIPO {
    public static void main(String[] args) {
        int year1, year2;
        double gini1, gini2, difference;
        String name, output;

        // Get country data from user
        Scanner stdin = new Scanner(System.in);
        System.out.print("Enter country name: ");
        name = stdin.nextLine();
        System.out.print("Enter first year: ");
        year1 = stdin.nextInt();
        System.out.print("Enter first year's Gini coefficient: ");
        gini1 = stdin.nextDouble();
        System.out.print("Enter second year: ");
        year2 = stdin.nextInt();
        System.out.print("Enter second year's Gini coefficient: ");
        gini2 = stdin.nextDouble();

        // Calculate Gini coefficient difference
        difference = gini2 - gini1;

        // Print results
        output = String.format("The Gini coefficient difference for %s ", name);
        output += String.format("between the years %d and %d is ", year1, year2);
        output += String.format("%.3f.", difference);
        System.out.println(output);
    }
}