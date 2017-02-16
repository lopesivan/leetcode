#include <vector>
#include <iostream>
#include <map>

using std::vector;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m;
        int size = nums.size();
        for(int i = 0; i < size; ++i) {
            int num = nums[i];
            auto iter = m.find(target-num);
            if (iter != m.end()) {
                return {iter->second, i};
            } else {
                m.insert(std::make_pair(num, i));
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 4};
    auto res = sol.twoSum(nums, 6);
    std::cout << res[0] << std::endl;
    std::cout << res[1] << std::endl;
    return 0;
}
