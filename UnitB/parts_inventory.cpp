#include <iostream>
#include <string>
#include <vector>

class Parts {
    private:
        std::string name;
        int count;
        int id;
    public:
      static int id_count;
      bool valid;
        Parts(std::string name, int count) {
            this->name = name;
            if (count > 0) {
              this->count = count;
              valid = true;
              this->id = id_count;
              id_count += count;
            }
            else {
              valid = false;
            }
        }
        bool sell(int number) {
            if (number <= count && valid) {
              count = count - number;
              return true;
            }
            else {
              return false;
            }
        }
        std::string get_type() {
            return this->name;
        }
        std::string to_string() const {
            if (valid) {
              return std::to_string(id) + ": " + name + " " + std::to_string(count);
            }
            else {
              return "";
            }
        }
};

int Parts::id_count = 1;

int main() {
  std::vector<Parts> parts;
  bool valid = true;
  
  // Constructor is passed part type and count.
  // When we create (for example) a Parts with count 20, they get id 1,
  // and the next Parts get id 21.
  // Use a static variable, not a global variable.
  parts.push_back(Parts("1/4x5 hex bolt", 5));      // id 1
  parts.push_back(Parts("6 inch spiral nail", 10)); // id 6
  parts.push_back(Parts("3/16 flat washer", 24));   // id 16
  try {
    parts.push_back(Parts("bad", -8));
  } catch (const std::runtime_error &ex) {
    std::cout << ex.what() << std::endl;
  }
  parts.push_back(Parts("#6 drywall screw", 100));  // id 40

  for (const auto &p : parts) {
    if (!p.valid) {
      valid = false;
    }
  }
  if (!valid) {
    std::cout << "attempted to create Parts with invalid count\n";
  }
  
  std::cout << "\nParts before:\n";
  for (const auto &p : parts) {
    if (p.valid) {
      std::cout << p.to_string() << std::endl;
    }
  }
  std::cout << std::endl;
  
  // "selling" parts decreases their count
  if (!parts.at(2).sell(10)) {
    // this should not print
    std::cout << "Not enough " << parts.at(2).get_type() << std::endl; 
  }

  if (!parts.at(0).sell(5)) {
    // this should not print
    std::cout << "Not enough " << parts.at(2).get_type() << std::endl; 
  }

  if (!parts.at(1).sell(20)) {
    // this should print, and nothing should be sold
    std::cout << "Not enough " << parts.at(1).get_type() << std::endl; 
  }

  if (!parts.at(3).sell(-1)) {
    // this should print, and nothing should be sold
    std::cout << "Invalid sale of " << parts.at(1).get_type() << std::endl;
  }
  
  std::cout << "\nParts after:\n";
  for (const auto &p : parts) {
    if (p.valid) {
      std::cout << p.to_string() << std::endl;
    }
  }
}