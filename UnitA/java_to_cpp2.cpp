#include <vector>
#include <iostream>

void sort(std::vector<int> nums) {
    if (nums.size() > 1) {
        for (int k = 0; k <= nums.size()-2; k++) {
            int min = nums.at(k);
            int where = k;
            for (int i = k+1; i < nums.size(); i++) {
                if (nums.at(i) < min) {
                    min = nums.at(i);
                    where = i;
                }
            }
            nums[where] = nums.at(k);
            nums[k] = min;
        }
    }

    std::cout << "[";
    for (int x : nums) {
        std::cout << x;
        if (x != nums.at(nums.size()-1)) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> test1 = {5, 3, 4, 1, 2};
    std::vector<int> test2 = {10, -10, 999, 0, -5, 5};
    std::vector<int> test3 = {1};
    std::vector<int> test4 = {};

    sort(test1);
    sort(test1);
    sort(test2);
    sort(test3);
    sort(test4);
}