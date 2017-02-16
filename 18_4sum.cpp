#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int end = nums.size();
        for(int i = 0; i < end - 3; ++i) {
            //std::cout << "i = " << i << std::endl;
            for(int j = i + 1; j < end - 2; ++j) {
                //std::cout << "j = " << j << std::endl;
                int dest = target - nums[i] - nums[j];
                int lower = j + 1;
                int upper = end - 1;
                while(lower < upper) {
                    //std::cout << "lower = " << lower << ", upper = " << upper << std::endl;
                    if(nums[lower] + nums[upper] == dest) {
                        std::cout << nums[i] << " + " << nums[j] << " + " 
                            << nums[lower] << " + " << nums[upper] << std::endl;
                        res.push_back({nums[i], nums[j], nums[lower], nums[upper]});
                        do {
                            lower++;
                        } while(lower < upper and nums[lower] == nums[lower-1]);
                    } else if(nums[lower] + nums[upper] < dest) {
                        ++lower;
                    } else {
                        --upper;
                    }
                }
                while(j + 1 < end - 2 and nums[j + 1] == nums[j]) {
                    ++j;
                }
            }
            while(i + 1 < end - 3 and nums[i + 1] == nums[i]) {
                ++i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, -1, 0, 0, 1, 2};
    sol.fourSum(nums, 0); 

    nums = {0, 0, 0, 1, 1, 2, 2, 3, 4};
    sol.fourSum(nums, 4); 

    return 0;
}
