#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
    public:
        int find_next_bar(vector<int>& height, int start) {
            int size = height.size();
            int max_i = size;
            int max_height = -1;
            for(int i = start + 1; i < size; ++i) {
                if(height[i] >= max_height) {
                    max_i = i;
                    max_height = height[i];
                }
                if(height[i] >= height[start]) {
                    break;
                }
            }
            return max_i;
        }
        int trap2(vector<int>& height) {
            int a = 0; 
            int b = find_next_bar(height, a);
            int size = height.size();
            int res = 0;
            //std::cout << "a = " << a << ", b = " << b  << std::endl;
            while(b < size) {
                int h = std::min(height[a], height[b]);
                //std::cout << "a = " << a << ", b = " << b 
                //    << ", h = " << h << std::endl;
                int sum = 0;
                for(int i = a + 1; i < b; ++i) {
                    if(h > height[i]) {
                        sum += h - height[i]; 
                    }
                }
                //std::cout << "sum = " << sum << std::endl;
                res += sum;
                a = b;
                b = find_next_bar(height, a);
            }
            return res;
        }

        int trap(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int left_max = 0;
            int right_max = 0;
            int res = 0;
            while(left < right) {
                if(height[left] < height[right]) {
                    if(height[left] >= left_max) {
                        left_max = height[left];
                    } else {
                        res += left_max - height[left]; 
                    }
                    ++left;
                } else {
                    if(height[right] >= right_max) {
                        right_max = height[right];
                    } else {
                        res += right_max - height[right]; 
                    }
                    --right;
                } 
            }
            return res;
        }
};

int main() {
    {
        vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        Solution sol;
        std::cout << sol.trap(input) << std::endl;
        assert(sol.trap(input) == 6);
    }
    {
        vector<int> input = {5, 2, 1, 2, 1, 5};
        Solution sol;
        std::cout << sol.trap(input) << std::endl;
        assert(sol.trap(input) == 14);
    }
    {
        vector<int> input = {4, 4, 4, 7, 1, 0};
        Solution sol;
        std::cout << sol.trap(input) << std::endl;
        assert(sol.trap(input) == 0);
    }
    {
        vector<int> input = {0, 0, 0, 2, 0, 8, 6, 7, 7};
        Solution sol;
        std::cout << sol.trap(input) << std::endl;
    }
    {
        vector<int> input = {0, 0, 1, 0, 0};
        Solution sol;
        std::cout << sol.trap(input) << std::endl;
    }
    return 0;
}
