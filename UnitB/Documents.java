public class Documents {
  public static void main(String[] args) {
    // name, positive size, date
    // assume date format is correct as "mmm dd yyyy"
    class Document {
        private String name;
        private int size;
        private String date;

        public Document(String name, int size, String date) {
            if (name == null) {
                throw new NullPointerException("invalid name " + name);
            }
            else if (size < 0) {
                throw new IllegalArgumentException("invalid size " + size);
            }

            this.name = name;
            this.size = size;
            this.date = date;
        }

        public Document(Document doc, int size, String date) {
            if (doc == null) {
                throw new NullPointerException("invalid name " + name);
            }
            else if ((doc.size() + size) < 0) {
                throw new IllegalArgumentException("invalid size " + (doc.size() + size));
            }

            this.name = doc.name();
            this.size = doc.size() + size;
            this.date = date;
        }

        public String name() {
            return this.name;
        }
        public int size() {
            return this.size;
        }
        public String month() {
            return this.date.substring(0,3);
        }
        public String day() {
            return this.date.substring(4,6);
        }
        public String year() {
            return this.date.substring(7,11);
        }
        public String date() {
            return this.date;
        }
        public String toString() {
            return "Document[name=" + this.name +", size=" + this.size + ", date=" + this.date +"]";
        }
        public boolean equals(Object o) {
            return this.name.equals(((Document)o).name) && this.size == ((Document)o).size && this.date.equals(((Document)o).date);
        }
    }

    Document doc1 = new Document("Comp2400.java", 200, "Oct 25 2025");
    Document doc2 = new Document("Final Report.txt", 5000, "Sep 19 2025");
    Document doc3 = new Document(doc2.name(), doc2.size() + 100, "Sep 22 2025");
    
    System.out.println("doc1: " + doc1);
    System.out.println("doc2: " + doc2);
    System.out.println("doc3: " + doc3);

    try {
      Document docBad = new Document("Bad.doc", -500, "Sep 19 2025");
    } catch (IllegalArgumentException iae) {
      System.out.println("unable to create docBad: " + iae.toString());
    }
    
    System.out.println("doc3's month: " + doc3.month());
    System.out.println("doc3's day: " + doc3.day());
    System.out.println("doc3's year: " + doc3.year());
    
    String doc4Date = doc2.month() + " " + doc2.day() + " " + doc2.year();
    Document doc4 = new Document(doc2.name(), doc2.size(), doc4Date);
    
    System.out.println("doc4: " + doc4);
    
    System.out.println("doc2.equals(doc3) ? " + doc2.equals(doc3));
    System.out.println("doc2.equals(doc4) ? " + doc2.equals(doc4));
    System.out.println("doc3.equals(doc4) ? " + doc3.equals(doc4));
    
    // existing document, change in size, new date
    Document doc5 = new Document(doc3, -400, "Oct 18 2025");

    System.out.println("doc5: " + doc5);

    try {
      Document docBad = new Document(doc1, -210, "Oct 31 2025");
    } catch (IllegalArgumentException iae) {
      System.out.println("unable to create docBad: " + iae.toString());
    }
  }
}