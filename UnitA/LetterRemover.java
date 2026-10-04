import java.util.ArrayList;
import java.util.Arrays;

public class LetterRemover {

  // modify the vector so that each word has the first letter removed
  // write the letterRemover function here:
  public static ArrayList<String> letterRemover(ArrayList<String> words) {
    ArrayList<String> result = words;
    int i = 0;
    for (String word : words) {
        if (word != null && word.length() > 0) {
            result.set(i, word.substring(1));
        }
        i = i + 1;
    }
    return result;
  }
  
  public static void main(String[] args) {
    var words1 = new ArrayList<String>( Arrays.asList("write", "some", "ArrayList", "and", "String", "code") );
    var words2 = new ArrayList<String>( Arrays.asList("a", "", "ccc") );
    var words3 = new ArrayList<String>( Arrays.asList( ) );
    var words4 = new ArrayList<String>( Arrays.asList("aaa", null, "zzz") );

    System.out.println(words1);
    letterRemover(words1);
    System.out.println(words1);

    System.out.println(words2);
    letterRemover(words2);
    System.out.println(words2);

    System.out.println(words3);
    letterRemover(words3);
    System.out.println(words3);

    System.out.println(words4);
    letterRemover(words4);
    System.out.println(words4);
  }
}
