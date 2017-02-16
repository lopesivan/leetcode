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

#define MAX_LEN 1000
class Solution {
    public:
        string longestPalindrome(string s) {
            int dp[MAX_LEN*2-1] = {0};
            int size = s.size();
            int end = std::max(2 * size - 1, 0);
            for(int i = 0; i < 2 * size - 1; i++) {
                int len;
                if(i % 2 == 1) {
                    len = 0;
                    for(int k = 1; i - k >= 0 and i + k < end; k += 2 ) {
                        if(s[(i-k)/2] == s[(i+k)/2]) {
                            len += 2;
                        } else {
                            break;
                        }
                    }
                } else {
                    len = 1;
                    for(int k = 2; i - k >= 0 and i + k < end; k += 2) {
                        if(s[(i-k)/2] == s[(i+k)/2]) {
                            len += 2;
                        } else {
                            break;
                        }
                    }
                }
                dp[i] = len;
            }
            for(int i = 0; i < 2 * size - 1; ++i) {
                std::cout << "dp[" << double(i) / 2 << "] = " << dp[i] << std::endl;
            }
            std::cout << std::endl;
            int i = std::max_element(dp, dp+end) - dp;
            int max_len = dp[i];
            double index = double(i) / 2;
            std::cout << "i = " << index << ", len = " << max_len << std::endl;
            return s.substr(index - double(dp[i] - 1) / 2, dp[i]);
        }
};

string test(string s) {
    string res = Solution().longestPalindrome(s);
    std::cout << res << std::endl;
    return res;
}

int main() {
    assert(test("babad") == "bab");
    assert(test("acbbcbcbbc") == "cbbcbcbbc");
    assert(test("aaaaba") == "aaaa");
    assert(test("cbbd") == "bb");
    assert(test("") == "");
    assert(test("a") == "a");
    return 0;
}
