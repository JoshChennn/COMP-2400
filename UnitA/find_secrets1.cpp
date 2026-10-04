#include <iostream>
#include <string>

const std::string target = "secrets";
const std::string message1 = "hello world there are no secrets in this message";
const std::string message2 = "this message really has none";
const std::string message3 = "secrets message has more than one secretsecrets i've got secrets";

const int count_occurrences(std::string text, const std::string target)
{
  int count = 0;
  
  while (text.length() > 0) {
    const auto pos = text.find(target);
    if (pos == std::string::npos) {
      text = "";
    } else {
      count++;
      text = text.substr(pos + 1);
    }
  }
  
  return count;
}

const int find_in_three(const std::string target, const std::string message1, const std::string message2, const std::string message3)
{
  int total = 0;
  
  total += count_occurrences(message1, target);
  total += count_occurrences(message2, target);
  total += count_occurrences(message3, target);
  
  return total;
}

int main()
{
  int total = find_in_three(target, message1, message2, message3);
  
  std::cout << "total number of matches found = " << total << "\n";
}