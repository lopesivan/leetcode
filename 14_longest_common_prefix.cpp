#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        string res = strs[0];
        int end = strs.size();
        for(int i = 1; i < end; ++i) {
            const string& curr = strs[i];
            int len = std::min(res.length(), curr.length());
            int index = 0;
            while(index < len) {
                if(curr[index] == res[index]) {
                    ++index;
                } else {
                    break;
                }
            }
            res = res.substr(0, index);
        }
        return res;
    }
};

int main() {
    vector<string> strs = {"abcdefg", "bc"};
    std::cout << Solution().longestCommonPrefix(strs);
    return 0;
}
