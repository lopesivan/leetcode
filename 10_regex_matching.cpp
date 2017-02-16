#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

inline bool match(char a, char b) {
    return a == b or b == '.';
}

class Solution {
    public:
        bool isMatch(string s, string p) {
            //std::cout << "s = " << s << ", p = " << p << std::endl;
            int end = s.size();
            int end_p = p.size();
            int index = 0;
            bool has_star = false;
            while(index < end and index < end_p) {
                char ch = p[index];
                has_star = index+1 < end_p && p[index+1] == '*';
                if(has_star) {
                    break;
                }
                if(!match(s[index], ch)) {
                    return false; 
                } else {
                    ++index;
                }
            }
            //std::cout << "index = " << index << std::endl;
            if(index >= end && index >= end_p) {
                return true;
            } else if(index >= end_p) {
                return false; 
            } else {
                has_star = index+1 < end_p && p[index+1] == '*';
                if(!has_star) {
                    return false;
                }
            }
            //std::cout << "has star" << std::endl;
            // has star
            string sub_p = p.substr(index+2, end_p);
            char ch = p[index];
            for(; index < end; ++index) {
                if(isMatch(s.substr(index, end), sub_p)) {
                    return true;
                }
                if(!match(s[index], ch)) {
                    break;
                }
            }
            return isMatch(s.substr(index, end), sub_p);
        }
};

int main() {
    Solution sol;
    assert(sol.isMatch("aa", "aa"));
    assert(!sol.isMatch("aa", "a"));
    assert(!sol.isMatch("a", "aa"));
    assert(sol.isMatch("aa", "a*"));
    assert(sol.isMatch("aab", "c*a*b"));
    assert(!sol.isMatch("aab", "c*a*d"));
    assert(sol.isMatch("bab", ".*b"));
    assert(!sol.isMatch("aaab", "b*b"));
    assert(sol.isMatch("a", "ab*"));
    assert(!sol.isMatch("", ".b*"));
    assert(!sol.isMatch("", "ab*"));
    return 0;
}
