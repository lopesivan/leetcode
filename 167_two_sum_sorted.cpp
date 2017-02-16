#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> twoSum_v1(vector<int>& numbers, int target) {
        vector<int> res;       
        int end = numbers.size();
        for(int i = 0; i < end; ) {
            int a = numbers[i];  
            int b = target - a;
            //assurance of solution make below iter no need checking
            auto iter = std::lower_bound(numbers.begin() + i + 1, numbers.end(), b);
            if(iter != numbers.end() and *iter == b) {
                std::cout << i << ", " << iter - numbers.begin() << std::endl;
                return {i + 1, int(iter - numbers.begin()) + 1};
            }
            while(numbers[++i] == a);
        }
        return res;
    }
 
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lower = 0;
        int upper = numbers.size() - 1;
        while(numbers[lower] + numbers[upper] != target) {
            if(numbers[lower] + numbers[upper] < target) {
                ++lower;
            } else {
                --upper;
            }
        }
        return {lower+1, upper+1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    auto res = sol.twoSum(nums, 7);
    std::cout << res[0] << ", " << res[1] << std::endl;
    nums = {2, 7, 11, 15};
    assert(sol.twoSum(nums, 9) == vector<int>({1, 2}));
    nums = {1, 4};
    assert(sol.twoSum(nums, 5) == vector<int>({1, 2}));
    nums = {1, 2, 3, 4};
    assert(sol.twoSum(nums, 7) == vector<int>({3, 4}));
    nums = {0, 0, 3, 4};
    assert(sol.twoSum(nums, 0) == vector<int>({1, 2}));
    nums = {3,24,50,79,88,150,345};
    sol.twoSum(nums, 200);
    //assert(sol.twoSum(nums, 200) == vector<int>({3, 4}));
    
    return 0;
}
