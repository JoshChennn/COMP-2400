import java.util.ArrayList;

public class SGC {
  public static void main(String[] args) {
    Course c1 = new Course("comp2140");
    Course c2 = new Course("comp2400");
    Course c3 = new Course("comp2450");
    Student s1 = new Student("aaa");
    Student s2 = new Student("bbb");
    Student s3 = new Student("ccc");
    
    s1.addGrade(c1, "B");
    s1.addGrade(c3, "A+");
    s2.addGrade(c1, "A");
    s2.addGrade(c2, "B+");
    s2.addGrade(c3, "B");
    s3.addGrade(c3, "B+");
    
    System.out.println(s1);
    System.out.println(s2);
    System.out.println(s3);
  }
}

class Course {
  /* declare classList as an ArrayList */
  private String name;
  public Course(String n) {
    /* any initialization required */
    this.name = n;
  }
  public void addStudent(/* parameter for a Student s */) {
    classList.add(s);
  }
  public String toString() {
    return "course: " + name + " has " + classList.size() + " students";
  }
}

class Grade {
  /* declare a single Course */
  private String grade;
  public Grade(/* parameter for a Course c */, String g) {
    /* any initialization required */
    this.grade = g;
  }
  public String toString() {
    return "Grade: " + grade + " in " + course;
  }
}

class Student {
  /* declare gradeList as an ArrayList */
  private String name;
  public Student(String n) {
    /* any initialization required */
    this.name = n;
  }
  public void addGrade(/* parameter for a Course c */, String grade) {
    gradeList.add(/* construct a Grade */);
  }
  public String toString() {
    return "Student " + name + " Grades: " + gradeList;
  }
}
