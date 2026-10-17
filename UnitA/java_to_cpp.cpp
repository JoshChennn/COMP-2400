#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::string> groupsOfN(std::string s, int n) {
    std::vector<std::string> result;

    for (int i = 0; i < s.size(); i += n) {
        int end = std::min(i + n, int(s.size()));
        result.push_back(s.substr(i,n));
    }

    std::cout << "[";
    for (std::string x : result) {
        std::cout << x;
        if (x != result.at(result.size()-1)) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    return result;
}

int main() {
    const std::string TEST1 = "hello world!";
    const std::string TEST2 = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
    const std::string TEST3 = "!@#$%^ &*()-=";

    groupsOfN(TEST1, 5);
    groupsOfN(TEST1, 6);
    groupsOfN(TEST2, 10);
    groupsOfN(TEST3, 1);
    groupsOfN(TEST3, 2);
}