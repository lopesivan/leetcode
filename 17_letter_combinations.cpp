#include <vector>
#include <iostream>
#include <string>
using namespace std;

void debug_res(vector<string> res) {
    for(auto elem : res) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            const static vector<string> tables = {"abc", "def", "ghi", "jkl",
                "mno", "pqrs", "tuv", "wxyz"};
            vector<string> res = {""};
            for(auto digit : digits) {
                int index = digit - '2';
                vector<string> temp_res = {};
                for(char ch : tables[index]) {
                    for(auto elem : res) {
                        temp_res.push_back(elem + ch);
                    }
                    //debug_res(res);
                }
                res = temp_res;
            }
            return res.size() == 1 && res[0] == "" ? vector<string>{} : res;
        }
};

int main() {
    Solution sol;
    debug_res(sol.letterCombinations("23"));
    debug_res(sol.letterCombinations("7945"));
    return 0;
}
