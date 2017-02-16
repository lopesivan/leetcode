#include <string>
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class Solution {
    public:
        char pair(char left) {
            switch(left) {
                case '(': return ')';
                case '{': return '}';
                case '[': return ']';
                default: return ' ';
            }
        }

        bool isValid(string s) {
            stack<char> stack = {};
            for(char ch : s) {
                char left;
                switch(ch) {
                    case '(':
                    case '{':
                    case '[':
                        stack.push(ch);
                        break;
                    case ')':
                    case ']':
                    case '}':
                        if(stack.empty()) {
                            return false;
                        } else {
                            left = stack.top();
                            if(pair(left) == ch) stack.pop();
                            else return false;
                        }
                }
            }
            return stack.size() == 0;
        }
};

int main() {
    assert(Solution().isValid("()[]{}"));
    assert(!Solution().isValid("(]"));
    assert(!Solution().isValid("([)]"));
    assert(!Solution().isValid("]"));
    return 0;
}
