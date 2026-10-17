public class Sum {
    public static void main(String[] args) {
        final String ONE = "123 -456 x 789\t10   0 8ad";
        final String TWO = "1234567890||-1234567890|0";
        final String THREE = ",1,2,3,4,5,6,seven,8,9,ten,,11,12,thirteen,14,15,-100";
        System.out.println(sum(ONE, "\\s+"));
        System.out.println(sum(TWO, "\\|"));
        System.out.println(sum(THREE, ","));
    }

    public static int sum(String nums, String separator) {
        int sum;
        sum = 0;
        String[] tokens;
        tokens = nums.split(separator);
        boolean errored;

        errored = false;
        for (var token : tokens) {
            try {
                if (token.length() > 0) {
                    sum += Integer.parseInt(token);
                }
            }
            catch (NumberFormatException nfe) {
                if (errored) {
                    System.out.print(",");
                }
                errored = true;
                System.out.print("bad:" + token);
            }
        }
        if (errored) {
            System.out.println();
        }

        // errored = false;
        // for (var token : tokens) {
        //     if (token.length() > 0) {
        //         try {
        //             sum += Integer.parseInt(token);
        //         }
        //         catch (NumberFormatException nfe) {
        //             errored = true;
        //             System.out.print("bad:" + token);
        //         }
        //     }
        // }
        // if (errored) {
        //     System.out.print(",");
        // }
        // if (errored) {
        //     System.out.println();
        // }

        return sum;
    }
}