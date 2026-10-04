public class CSVSum {
  public enum Select {
    NEGATIVE, POSITIVE, ALL
  }
  
  public static void main(String[] args) {
    System.out.print(csvSum(Select.ALL, "100,2,-45834,13,7189,-22,0") + ",");
    System.out.print(csvSum(Select.POSITIVE, "100,2,-45834,13,7189,-22,0") + ",");
    System.out.println(csvSum(Select.NEGATIVE, "100,2,-45834,13,7189,-22,0"));

    System.out.print(csvSum(Select.ALL, "1,-2,3,-4,5,-6,7,-8,9,-10") + ",");
    System.out.print(csvSum(Select.POSITIVE, "1,-2,3,-4,5,-6,7,-8,9,-10") + ",");
    System.out.println(csvSum(Select.NEGATIVE, "1,-2,3,-4,5,-6,7,-8,9,-10"));

    System.out.print(csvSum(Select.ALL, "a,999,b") + ",");
    System.out.print(csvSum(Select.POSITIVE, "a,999,b") + ",");
    System.out.println(csvSum(Select.NEGATIVE, "a,999,b"));

    System.out.print(csvSum(Select.ALL, "abc") + ",");
    System.out.print(csvSum(Select.POSITIVE, "abc") + ",");
    System.out.println(csvSum(Select.NEGATIVE, "abc"));

    System.out.print(csvSum(Select.ALL, "") + ",");
    System.out.print(csvSum(Select.POSITIVE, "") + ",");
    System.out.println(csvSum(Select.NEGATIVE, ""));
  }

  private static int csvSum(Select type, String nums) {
    int sum = 0;
    String[] spl = nums.split(",");
    if (type == Select.ALL) {
        for (int i = 0; i < spl.length; i++) {
            try {
                sum = sum + Integer.parseInt(spl[i]);
            } catch (Exception NaN) {}
        }
    }
    else if (type == Select.POSITIVE) {
        for (int i = 0; i < spl.length; i++) {
            try {
                if (Integer.parseInt(spl[i]) > 0) {
                    sum = sum + Integer.parseInt(spl[i]);
                }
            } catch (Exception NaN) {}
        }
    }
    else {
        for (int i = 0; i < spl.length; i++) {
            try {
                if (Integer.parseInt(spl[i]) < 0) {
                    sum = sum + Integer.parseInt(spl[i]);
                }
            } catch (Exception NaN) {}
        }
    }
    return sum;
  }
}