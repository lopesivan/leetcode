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

class Solution {
public:
    double myPow(double x, int n) {
        //std::cout << "x = " << x << ", n = " << n << std::endl;
        if(n == 0) {
            return 1;
        } else if(n == 1) {
            return x;
        } else if(n < 0) {
            double half_res = myPow(x, -(n/2));
            double pos_res = n % 2 == 0 ? half_res * half_res : half_res * half_res * x;
            return 1 / pos_res;
        } 
        double half = myPow(x, n/2);
        return n % 2 == 0 ? half * half : half * half * x;
    }
};

double test(double x, int n) {
    double res = Solution().myPow(x, n);
    std::cout << "res = " << res << std::endl;
    return res;
}

int main() {
    test(0, 0);
    test(0, 1);
    test(2, 10);
    test(2, 11);
    test(34.00515, -3);
    test(1.00000, -2147483648);
    return 0;
}
