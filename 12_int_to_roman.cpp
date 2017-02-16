#include <string>
#include <iostream>
#include <cassert>
#include <array>

using namespace std;

class Solution {
public:
    string intToRoman_v1(int num) {
        string res;
        int val = 0;
        if(num >= 1000) {
            res = "M";
            val = 1000;
        } else if(num >= 900) {
            res = "CM";
            val = 900;
        } else if(num >= 500) {
            res = "D";
            val = 500;
        } else if(num >= 400) {
            res = "CD";
            val = 400;
        } else if(num >= 100) {
            res = "C"; 
            val = 100;
        } else if(num >= 90) {
            res = "XC"; 
            val = 90;
        } else if(num >= 50) {
            res = "L"; 
            val = 50;
        } else if(num >= 40) {
            res = "XL";
            val = 40;
        } else if(num >= 10) {
            res = "X"; 
            val = 10;
        } else if(num >= 9) {
            res = "IX";
            val = 9;
        } else if(num >= 5) {
            res = "V";
            val = 5;
        } else if(num >= 4) {
            res = "IV";
            val = 4;
        } else if(num >= 1) {
            res = "I";
            val = 1;
        }
        // cout << val << " = " << res << endl;
        if(val == num) {
            return res;
        } else {
            return res + intToRoman_v1(num - val);
        }
    }

    string intToRoman(int num) {
        int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"};
        // assert(sizeof(vals) / sizeof(vals[0]) == sizeof(strs) / sizeof(strs[0]));
        string res;
        int len = sizeof(vals) / sizeof(vals[0]);
        for(int i = 0; i < len; ++i) {
            int val = vals[i];
            while(num >= val) {
                res += strs[i];
                num -= val;
            }
        }
        return res;
    }

};

int main() {
    Solution sol;
    assert(sol.intToRoman(621) == "DCXXI");
    assert(sol.intToRoman(1954)== "MCMLIV");
    assert(sol.intToRoman(1990)== "MCMXC");
    assert(sol.intToRoman(2014)== "MMXIV");
    cout << sol.intToRoman(1) << endl;
    cout << sol.intToRoman(3999) << endl;
    return 0;
}
