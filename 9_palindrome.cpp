#include <iostream>
#include <cassert>

class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0) {
                return false;
            } else if (x < 10) {
                return true;
            } else if (x % 10 == 0) {
                return false;
            }
            int res = 0;
            while(x > res) {
                res = res * 10 + x % 10;
                x /= 10;
            }
            //printf("res = %d, x = %d\n", res, x);
            //return res == x || (x > 0 and x == res / 10);
            return res == x || x == res / 10;
        }
};

int main() {
    Solution sol;
    assert(sol.isPalindrome(43234));
    assert(sol.isPalindrome(0));
    assert(sol.isPalindrome(1));
    assert(sol.isPalindrome(1234554321));
    assert(!sol.isPalindrome(4850993));
    assert(!sol.isPalindrome(-2147447412));
    assert(!sol.isPalindrome(2147483647));
    assert(!sol.isPalindrome(10));
    assert(!sol.isPalindrome(100));
    assert(sol.isPalindrome(1001));
    assert(!sol.isPalindrome(131000));
    return 0;
}
