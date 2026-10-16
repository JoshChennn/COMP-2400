#include <iostream>
#include <vector>

void print_string_vector(const std::vector<std::string> &v)
{
  std::cout << "[ ";
  for (const auto &s : v) {
    std::cout << s << " ";
  }
  std::cout << "]\n";
}

// the merge function receives two *sorted* vectors
// it combines the contents of the two into a single *sorted* vector
// do not modify either of the original vectors
// write the merge function here:
std::vector<std::string> merge(const std::vector<std::string> &v1, const std::vector<std::string> &v2) {
    std::vector<std::string> result;
    int count = 0;
    if (v1.size() == 0) {
        result = v2;
    }
    else if (v2.size() == 0) {
        result = v1;
    }
    else {
        std::vector<std::string> longer;
        std::vector<std::string> shorter;
        if (v1.size() >= v2.size()) {
            longer = v1;
            shorter = v2;
        }
        else {
            longer = v2;
            shorter = v1;
        }
        for (std::string word : longer) {
            if (shorter.size() > 0) {
                while (count < shorter.size() && shorter.at(count)[0] <= word[0]) {
                    result.push_back(shorter.at(count));
                    count++;
                }
                result.push_back(word);
                if (word == longer.at(longer.size()-1)) {
                    for (std::string word2 : shorter) {
                        if (word2[0] > word[0]) {
                            result.push_back(word2);
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
  std::vector<std::string> sorted1 { "cc", "ee", "ff", "hh", "jj" };
  std::vector<std::string> sorted2 { "aa", "bb", "dd", "gg", "ii", "kk" };
  std::vector<std::string> sorted3 { "k", "l", "m" };
  std::vector<std::string> sorted4;

  print_string_vector(merge(sorted1, sorted1));
  print_string_vector(merge(sorted1, sorted2));
  print_string_vector(merge(sorted1, sorted3));
  print_string_vector(merge(sorted1, sorted4));

  print_string_vector(merge(sorted2, sorted1));
  print_string_vector(merge(sorted2, sorted2));
  print_string_vector(merge(sorted2, sorted3));
  print_string_vector(merge(sorted2, sorted4));

  print_string_vector(merge(sorted3, sorted1));
  print_string_vector(merge(sorted3, sorted2));
  print_string_vector(merge(sorted3, sorted3));
  print_string_vector(merge(sorted3, sorted4));

  print_string_vector(merge(sorted4, sorted1));
  print_string_vector(merge(sorted4, sorted2));
  print_string_vector(merge(sorted4, sorted3));
  print_string_vector(merge(sorted4, sorted4));
}