#include <iostream>

std::string string_rep(std::string &phrase, std::string modify) {
    for (int i = 0; i < modify.length(); i += 2) {
        for (int j = 0; j < phrase.length(); j++) {
            if (phrase.at(j) == modify.at(i)) {
                if (modify.length() % 2 != 0 && i == modify.length() - 1) {
                    phrase.erase(j,1);
                    j--;
                }
                else {
                    phrase[j] = modify.at(i+1);
                }
            }
        }
    }
    return phrase;
}

int main() {
  // the function string_rep modifies the first string parameter,
  // using the information in the second string parameter

  // the second parameter starts with pairs of characters, every
  // instance of the first character is replaced by the second

  // if there are an odd number of characters in the pattern, any
  // matches to the last letter in the pattern are removed from
  // the string

  // hint: use .at() instead of [] to access characters to avoid
  // out-of-bound strangeness
  
  std::string hello_world = "hello, world!";
  std::cout << hello_world << std::endl;
  string_rep(hello_world, ",.!?");
  std::cout << hello_world << std::endl;
  string_rep(hello_world, "l1o0e3hH");
  std::cout << hello_world << std::endl;
  string_rep(hello_world, "");
  std::cout << hello_world << std::endl;
  string_rep(hello_world, "w");
  std::cout << hello_world << std::endl;

  std::string abc = "aaabbbcbbbcaaaabbba";
  string_rep(abc, "b-c+a");
  std::cout << abc << std::endl;
}