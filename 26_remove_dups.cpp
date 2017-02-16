#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

void debug_list(vector<int> lst) {
    for(auto elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int count = 0;
            int end = nums.size();
            int tail = 0;
            int index = 0;
            while(index < end) {
                int num = nums[index];
                while(++index < end && nums[index] == num) {}
                nums[tail++] = num;
                ++count;
            }
            return count;
        }
};

int test_list(vector<int> lst) {
    int res = Solution().removeDuplicates(lst);
    std::cout << "res = " << res << std::endl;
    for(int i = 0; i < res; ++i) {
        std::cout << lst[i] << " ";
    }
    std::cout << std::endl;
    return res;
}

int main() {
    test_list({1, 1, 1, 2, 2, 3, 3});
    test_list({1, 2, 3});
    test_list({});
    test_list({1, 1, 1});
    return 0;
}
