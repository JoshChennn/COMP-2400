import java.util.ArrayList;
import java.util.Arrays;

public class Merger {

  // the merge function receives two *sorted* ArrayLists
  // it combines the contents of the two into a single *sorted* ArrayList
  // do not modify either of the original ArrayLists
  // write the merge function here:
  private static ArrayList<Integer> merge(ArrayList<Integer> string1, ArrayList<Integer> string2) {
    ArrayList<Integer> result = new ArrayList<Integer>();
    int num2 = 0;
    if (string1.size() == 0) {
      result = string2;
    }
    else if (string2.size() == 0) {
      result = string1;
    }
    else {
      ArrayList<Integer> longer = new ArrayList<Integer>();
      ArrayList<Integer> shorter = new ArrayList<Integer>();
      if (string1.size() >= string2.size()) {
        longer = string1;
        shorter = string2;
      }
      else {
        longer = string2;
        shorter = string1;
      }
      for (int num : longer) {
          if (shorter.size() > 0) {
              while (num2 < shorter.size() && shorter.get(num2) <= num) {
                  result.add(shorter.get(num2));
                  num2 = num2 + 1;
              }
              result.add(num);
              if (num == longer.get(longer.size()-1)) {
                for (int num3 : shorter) {
                  if (num3 > num) {
                    result.add(num3);
                  }
                }
              }
          }
      }
    }
    return result;
  }

  
  public static void main(String[] args) {
    var sorted1 = new ArrayList<Integer> ( Arrays.asList(33, 55, 66, 88, 100) );
    var sorted2 = new ArrayList<Integer> ( Arrays.asList(11, 22, 44, 77, 99, 999) );
    var sorted3 = new ArrayList<Integer> ( Arrays.asList(5, 50, 110) );
    var sorted4 = new ArrayList<Integer> ();

    System.out.println(merge(sorted1, sorted1));
    System.out.println(merge(sorted1, sorted2));
    System.out.println(merge(sorted1, sorted3));
    System.out.println(merge(sorted1, sorted4));

    System.out.println(merge(sorted2, sorted1));
    System.out.println(merge(sorted2, sorted2));
    System.out.println(merge(sorted2, sorted3));
    System.out.println(merge(sorted2, sorted4));

    System.out.println(merge(sorted3, sorted1));
    System.out.println(merge(sorted3, sorted2));
    System.out.println(merge(sorted3, sorted3));
    System.out.println(merge(sorted3, sorted4));

    System.out.println(merge(sorted4, sorted1));
    System.out.println(merge(sorted4, sorted2));
    System.out.println(merge(sorted4, sorted3));
    System.out.println(merge(sorted4, sorted4));
  }
}