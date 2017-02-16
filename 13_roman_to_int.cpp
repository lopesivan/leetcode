#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    int romanToInt(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int res = 0;
        int len = s.length();
        for(int i = 0; i < len; ++i) {
            char c = s[i];
            int val = romanToInt(c);
            if(i + 1 < len) {
                int next_val = romanToInt(s[i+1]);
                if(next_val > val) {
                    res += next_val - val;
                    ++i;
                    continue;
                }
            }
            res += val;
        }
        return res;
    }
};

int main() {
    printf("%d", Solution().romanToInt("MCMLIV"));
    assert(Solution().romanToInt("DCXXI") == 621);
    assert(Solution().romanToInt("MCMLIV") == 1954);
    assert(Solution().romanToInt("MCMXC") == 1990);
    assert(Solution().romanToInt("MMXIV") == 2014);
    return 0;
}
