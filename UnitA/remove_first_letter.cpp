#include <iostream>
#include <vector>

void print_string_vector(const std::vector<std::string> &v)
{
  for (const auto &s : v) {
    std::cout << s << " ";
  }
}

// write the remove_first_letter function here:
void remove_first_letter(std::vector<std::string> &words) {
    //words.push_back("test");
    for (std::string &word : words) {
        if (word.size() > 0) {
            word = word.substr(1,word.size()-1);
        }
    }
}


int main()
{
  std::vector<std::string> words1 { "write", "some", "vector", "AND", "string", "code" };
  std::vector<std::string> words2 { "a", "", "ccc" };
  std::vector<std::string> words3;

  std::cout << "the original vector: |";
  print_string_vector(words1);
  remove_first_letter(words1);
  std::cout << "|\nthe words without their first letter: |";
  print_string_vector(words1);
  std::cout << "|\n";

  std::cout << "the original vector: |";
  print_string_vector(words2);
  remove_first_letter(words2);
  std::cout << "|\nthe words without their first letter: |";
  print_string_vector(words2);
  std::cout << "|\n";

  std::cout << "the original vector: |";
  print_string_vector(words3);
  remove_first_letter(words3);
  std::cout << "|\nthe words without their first letter: |";
  print_string_vector(words3);
  std::cout << "|\n";
}