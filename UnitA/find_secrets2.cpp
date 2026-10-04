#include <iostream>
#include <string>

std::string target = "secrets";
std::string message1 = "hello world there are no secrets in this message";
std::string message2 = "this message really has none";
std::string message3 = "secrets message has more than one secretsecrets i've got secrets";

const void erase_from_start(std::string &text, const int end)
{
  text.erase(0, end);
}

const int count_occurrences(std::string &text, const std::string &target)
{
  int count = 0;
  
  while (text.length() > 0) {
    const auto pos = text.find(target);
    if (pos == std::string::npos) {
      erase_from_start(text, text.length());
    } else {
      count++;
      erase_from_start(text, pos + 1);
    }
  }
  
  return count;
}

const int find_in_three(const std::string &target, std::string &message1, std::string &message2, std::string &message3)
{
  int total = 0;
  
  total += count_occurrences(message1, target);
  total += count_occurrences(message2, target);
  total += count_occurrences(message3, target);
  
  return total;
}

int main()
{
  const int total = find_in_three(target, message1, message2, message3);
  
  std::cout << "total number of matches found = " << total << "\n";
}
