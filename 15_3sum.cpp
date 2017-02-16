#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> nums_list = nums;
        int end = nums_list.size();
        std::sort(nums_list.begin(), nums_list.end());
        //for(auto elem : nums_list) {
        //    std::cout << elem << " "; 
        //}
        //std::cout << std::endl;
        for(int i = 0; i < end and nums_list[i] <= 0; ) {
        //    std::cout << "i = " << i << std::endl;
            int target = -nums_list[i];
            int lower = i + 1;
            int upper = end - 1;
            while(lower < upper) {
         //       std::cout << "lower = " << lower << ", upper = " << upper << std::endl;
                int val = nums_list[lower] + nums_list[upper];
                if(val == target) { //find
          //          std::cout << nums_list[i] << " + " << nums_list[lower] << " + " << nums_list[upper] << std::endl;
                    res.push_back({nums_list[i], nums_list[lower], nums_list[upper]});
                    // skip same lower in case of duplicate
                    do {
                        ++lower;
                    } while(lower < end and nums_list[lower] == nums_list[lower-1]);
                } else if(val < target) {
                    ++lower;
                } else {
                    --upper;
                }
            }

            do {
                ++i;
              // all vaild sol for such dest has been counted
            } while(i < end and nums_list[i] == nums_list[i-1]);
        }  
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    sol.threeSum(nums);

    nums = {-1, -1, -1, 0, 0, 0, 1, 1, 1, 2, 3};
    sol.threeSum(nums);

    nums = {-1, -1, 0, 0, 0, 1, 1, 1, 2, 3};
    sol.threeSum(nums);

    return 0;
}
