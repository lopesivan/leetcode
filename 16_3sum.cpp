#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2]; 
        int end = nums.size();
        //for(auto elem : nums) {
        //    std::cout << elem << " ";
        //}
        //std::cout << std::endl;
        for(int i = 0; i <  end - 2; ++i) {
            //std::cout << "i = " << i << std::endl;
            int val_i = nums[i];
            int lower = i + 1;
            int upper = end - 1;
            while(lower < upper) {
                //std::cout << "lower = " << lower 
                //    << ", upper = " << upper << std::endl;
                int val = nums[lower] + nums[upper] + val_i; 
                if(abs(target - sum) > abs(target - val)) {
                //    std::cout << nums[i] << " + " << nums[lower]
                //        << " + "  << nums[upper]
                //        << " = " << val << std::endl;
                    sum = val;
                }
                if(val == target) {
                    break; 
                } else if(val < target) {
                    ++lower;
                } else {
                    --upper; 
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    std::cout << sol.threeSumClosest(nums, 1) << std::endl;
    
    nums = {1, 1, 1, 2, 3, 4, 5, 6};
    std::cout << sol.threeSumClosest(nums, 7) << std::endl;
    
    nums = {1, 1, 1};
    std::cout << sol.threeSumClosest(nums, 1) << std::endl;

    return 0;
}
