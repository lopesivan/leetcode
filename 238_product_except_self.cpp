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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int end = nums.size();
        for(int i = 1; i < end; ++i) {
            res[i] = res[i-1] * nums[i-1];
        }
        //debug_list(res);

        int product = 1;
        for(int i = end-1; i >= 0; --i) {
            res[i] *= product;
            product *= nums[i];
        }
        //debug_list(res);
        return res;
    }
};

vector<int> test_list(vector<int> lst) {
    Solution sol;
    auto res = sol.productExceptSelf(lst);
    debug_list(res);
    return res;
}

int main() {
    test_list({1, 2, 3, 4});
    test_list({});
    test_list({1});
    test_list({1, 2});
    return 0;
}
