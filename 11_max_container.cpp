#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int end = height.size(); 
        int area = 0;
        int lower = 0;
        int upper = end - 1;
        while(lower < upper) {
            int curr_area = (upper - lower) * std::min(height[upper], height[lower]);
            area = std::max(curr_area, area);
            //std::cout << "lower=" << lower << ", upper=" << upper
            //    << ", area=" << curr_area << std::endl;
            if(height[lower] <= height[upper]) {
                do {
                    ++lower;
                } while(lower < upper and height[lower] <= height[lower - 1]);
            } else {
                do {
                    --upper;
                } while(lower < upper and height[upper] <= height[upper + 1]);
            }
        }
        //std::cout << "res: " << area << std::endl;
        return area;
    }
};

int main() {
    Solution sol;
    {
        vector<int> height = {0, 1, 2, 3, 4, 3, 2, 1};
        assert(sol.maxArea(height) == 8);
    }
    {
        vector<int> height = {0, 1, 2, 3, 4, 1, 2, 3, 4};
        assert(sol.maxArea(height) == 16);
    }
    return 0;
}
