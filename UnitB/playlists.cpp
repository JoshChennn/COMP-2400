#include <iostream>
#include <string>
#include <vector>

class Song
{
  std::string title;
  int length;

public:
  Song(std::string title, int length) : title(title), length(length) {
    // do *not* write any code here
  }
  

  
  bool sameTitle(const Song &other) /* code goes here */ {

  }
  
  std::string to_string() /* code goes here */ {
    return title + " (" + std::to_string(length) + " seconds)";
  }
};

class Playlist
{
  std::string name;
  std::vector<Song> list;

public:
  Playlist(std::string name) : name(name) {
    // do *not* write any code here
  }
  
  void add(const Song &song) {
    bool contains = false;
    if (song.valid()) {

    }
  }
  
  std::string to_string() /* code goes here */ {
    std::string result = "Playlist '" + name + "':\n";
    for (const auto &s : list) {
      result += " " + s.to_string() + "\n";
    }
    return result;
  }
};

int main()
{
  // Duplicate titles and invalid songs cannot be stored in playlists.
  // It may still be ok to *create* invalid Song objects. 
  
  Playlist workout("My Workout Playlist");
  Playlist chill("Chill");

  workout.add(Song("Warmup", 210));
  workout.add(Song("Short Tune", 100));
  workout.add(Song("", 100));
  workout.add(Song("Short Tune", 101));
  workout.add(Song("One Great City!", 204));
  workout.add(Song("Keep Going", 333));
  workout.add(Song("Cooldown", 450));
  
  chill.add(Song("Bad Start", -1));
  const Song c_song("4'33", 273);
  chill.add(c_song);
  chill.add(Song("This Song Goes On Forever", 1200));
  chill.add(Song("Lullaby", 321));
  
  const Playlist c_chill = chill; 
  
  std::cout << workout.to_string() << std::endl;
  std::cout << chill.to_string() << std::endl;
  std::cout << "Immutable " << c_chill.to_string() << std::endl;
  std::cout << "End of processing.\n";
}