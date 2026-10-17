import java.util.ArrayList;

public class Playlists {
  public static void main(String[] args) {
    // Duplicate titles and invalid songs cannot be stored in playlists.
    // It may still be ok to *create* invalid Song objects. 
    
    Playlist workout = new Playlist("My Workout Playlist");
    Playlist chill = new Playlist("Chill");

    workout.add(new Song("Warmup", 210));
    workout.add(new Song("Short Tune", 100));
    workout.add(null);
    workout.add(new Song(null, 100));
    workout.add(new Song("Short Tune", 101));
    workout.add(new Song("One Great City!", 204));
    workout.add(new Song("Keep Going", 333));
    workout.add(new Song("Cooldown", 450));
    
    chill.add(new Song("Bad Start", -1));
    chill.add(new Song("4'33", 273));
    chill.add(new Song("This Song Goes On Forever", 1200));
    chill.add(new Song("Lullaby", 321));
    
    System.out.println(workout);
    System.out.println(chill);
    System.out.println("End of processing.");
  }
}

class Playlist {
  private String name;
  private ArrayList<Song> list = new ArrayList<Song>();
  
  public Playlist(String name) {
    this.name = name;
  }
  
  public void add(Song song) {
    boolean contains = false;
    if (song != null && song.valid()) {
      boolean duplicate = false;
      for (Song s : list) {
        if (s.title == song.title) {
          duplicate = true;
        }
      }
      if (duplicate == false) {
        list.add(song);
      }
    }
  }
  
  public String toString() {
    String result = "Playlist '" + name + "':\n";
    try {
      for (var s : list) {
        result += " " + s.toString() + "\n";
      }
    } catch (NullPointerException npe) {

    }
    return result;
  }
}

class Song {
  public String title;
  private int length;
  
  public Song(String title, int length) {
    this.title = title;
    this.length = length;
  }
  
  public boolean valid() {
    if (this.length < 0 || this.title == null) {
      return false;
    }
    else {
      return true;
    }
  }

  public boolean sameTitle(Song other) {
    if (title.equals(other.title)) {
      return true;
    }
    else {
      return false;
    }
  }
  
  public String toString() {
    return title + " (" + length + " seconds)";
  }
}