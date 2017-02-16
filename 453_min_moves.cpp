#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;

void debug_list(vector<int> lst) {
    for(auto elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.empty()) {return 0;}
        int min = *std::min_element(nums.begin(), nums.end());
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return sum - min * nums.size();
    }
};

int test_list(vector<int> lst) {
    int res = Solution().minMoves(lst);
    std::cout << res << std::endl;
    return res;
}

int main() {
    assert(test_list({1, 2, 3}) == 3);
    assert(test_list({1, 1, 1}) == 0);
    assert(test_list({}) == 0);
    assert(test_list({1}) == 0);
    assert(test_list({2, 4, 6}) == 6);
    return 0;
}
