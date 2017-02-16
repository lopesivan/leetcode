#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;

void debug_list(vector<int> lst) {
    for(auto elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int end = nums.size();
            int i = end - 1;
            while(--i >=0 and nums[i] >= nums[i+1]) {}
            //std::cout << "nums["<< i << "] = " << nums[i] << std::endl;
            //TODO: i == 0 
            if(i >= 0) {
                //std::cout << "bound " << nums.rend() - nums.rbegin() << "-" << i << std::endl;
                int j = nums.rend()-1 - std::upper_bound(nums.rbegin(), nums.rend()-1-i, nums[i]);
                //auto iter = std::upper_bound(nums.rbegin(), nums.rend()-1-i, nums[i]);
                //std::cout << "end = " << *(nums.rend()-1-i) << std::endl;
                //std::cout << "upper = " << "nums[" << j << "]=" << nums[j] << std::endl;
                std::swap(nums[i], nums[j]);
            }

            for(int a = i + 1, b = end -1; a < b; ++a, --b) {
                std::swap(nums[a], nums[b]);
            }
            //debug_list(nums);
        }
};

void test_list(vector<int> lst) {
    Solution().nextPermutation(lst);
}

int main() {
    vector<int> lst = {1, 1, 2};
    vector<int> temp = lst;
    for(int i = 0; i < 10; ++i) {
        std::cout << "i = " << i << std::endl;
        Solution().nextPermutation(lst);
        std::next_permutation(temp.begin(), temp.end());
        debug_list(temp);
        assert(temp == lst);
    }
    return 0;
}
