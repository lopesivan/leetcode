#include <cstdio>
#include <cassert>
#include <climits>

class Solution {
    public:
        int reverse(int x) {
            bool is_negative = x < 0;
            if(is_negative) {
                x = -x;
            }
            int res = 0;
            unsigned long last = res;
            while(x != 0) {
                last = last * 10 + x % 10;
//                printf("last = %lu\n", last);
                if(last > INT_MAX) {
                    res = 0;
                    x = 0;
                    return res;
                } else {
                    res = (int)last;
                }
                //printf("res = %d\n", res);
                x /= 10;
            }
            if(is_negative) {
                res = -res;
            }
            return res; 
        }
};

int main() {
    Solution sol = Solution();
    //printf("%d\n", sol.reverse(1534236469));
    assert(sol.reverse(-200) == -2);
    assert(sol.reverse(-1234) == -4321);
    assert(sol.reverse(123) == 321);
    assert(sol.reverse(-123) == -321);
    assert(sol.reverse(-1) == -1);
    assert(sol.reverse(0) == 0);
    assert(sol.reverse(1534236469) == 0);
    return 0;
}
