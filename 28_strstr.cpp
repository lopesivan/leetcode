#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int end_i = haystack.size();
        int end_j = needle.size();
        for(; i <= end_i; ++i) {
            if(i + end_j > end_i) {
                break;
            }
            int j = 0;
            for(; j < end_j; ++j) {//substring
                if(i + j > end_i) {
                    return -1; 
                }
                if(haystack[i+j] != needle[j]) {
                    break;
                }
            }
            std::cout << "i = " << i << ", j = " << j << std::endl;
            if(j >= end_j) {
                return i;
            } 
        }
        return -1;
    }
};

int wrapper(string haystack, string needle) {
    int res = Solution().strStr(haystack, needle);
    std::cout << res << std::endl;
    return res;
}

int main() {
    Solution sol;
    assert(wrapper("12321", "1234") == -1);
    assert(wrapper("12321", "21") == 3);
    assert(wrapper("", "1") == -1);
    assert(wrapper("4", "") == 0);
    assert(wrapper("", "") == 0);
    return 0;
}
