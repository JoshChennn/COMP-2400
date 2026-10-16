import java.util.ArrayList;

public class A41 {
  
  public static void main(String[] args) {
    final String TEST1 = "hello world!";
    final String TEST2 = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
    final String TEST3 = "!@#$%^ &*()-=";
    
    System.out.println(groupsOfN(TEST1, 5));
    System.out.println(groupsOfN(TEST1, 6));
    System.out.println(groupsOfN(TEST2, 10));
    System.out.println(groupsOfN(TEST3, 1));
    System.out.println(groupsOfN(TEST3, 2));
  }
  
  public static ArrayList<String> groupsOfN(String s, int n) {
    var result = new ArrayList<String>();
    
    for (int i = 0; i < s.length(); i += n) {
      int end = Math.min(i + n, s.length());
      result.add(s.substring(i, end));
    }
    
    return result;
  }
}