#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(const vector<vector<int>> & matrix);

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; ++i) { // row
            int end = n - 1;
            for(int j = i; j < end - i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[end-j][i];
                matrix[end-j][i] = matrix[end-i][end-j];
                matrix[end-i][end-j] = matrix[j][end-i];
                matrix[j][end-i] = temp;
            }
        }
    }
};

void printMatrix(const vector<vector<int>> & matrix) {
    for(auto row : matrix) {
        for(auto elem : row) {
            std::cout << std::setfill('0') << std::setw(2) << elem << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}; 
    //vector<vector<int>> matrix = {{1, 2}, {3, 4}};
    //vector<vector<int>> matrix = {{1}};
    //vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    printMatrix(matrix);
    sol.rotate(matrix);
    printMatrix(matrix);
    return 0;
}
