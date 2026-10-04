final public class FindSecrets {
  final static String target = "secrets";
  final static String message1 = "hello world there are no secrets in this message";
  final static String message2 = "this message really has none";
  final static String message3 = "secrets message has more than one secretsecrets i've got secrets";
  
  final public static void main(final String[] args) {
    final int total = findInThree(target, message1, message2, message3);
  
    System.out.printf("total number of matches found = %d\n", total);
  }

  final public static int findInThree(final String target, final String message1, final String message2, final String message3)
  {
    int total = 0;
  
    total += countOccurrences(message1, target);
    total += countOccurrences(message2, target);
    total += countOccurrences(message3, target);
  
    return total;
  }

  final public static int countOccurrences(String text, final String target)
  {
    int count = 0;
  
    while (text.length() > 0) {
      final var pos = text.indexOf(target);
      if (pos < 0) {
        text = "";
      } else {
        count++;
        text = text.substring(pos + 1);
      }
    }
  
    return count;
  }
}