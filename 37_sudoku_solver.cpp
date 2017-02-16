#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#define foreach_grid(i, j) for(int i = 0; i < 9; ++i) for(int j = 0; j < 9; ++j) 
#define rep(i,n) for(int i = 0; i < n; ++i)
//#define DEBUG
#define debug_set(s) for(auto elem : s) { std::cout << elem << " "; } std::cout << std::endl;
#define for_in_block(k,i,j) int row_start = k / 3 * 3; int col_start = k % 3 * 3; for(int i = row_start; i < row_start + 3; ++i) for(int j = col_start; j < col_start + 3; ++j)

inline int get_block(int i, int j) {
    return (i / 3) * 3 + j / 3;
}

void print_board(const vector<vector<char>>& board);

class Solution {
    public:
        bool settled_values(vector<vector<char>>& board, set<char> row_area[], set<char> col_area[], set<char> block_area[]) {
            foreach_grid(i, j) {
                int k = get_block(i, j);
                char var = board[i][j];
                if(var != '.') {
                    assert(row_area[i].count(var) == 0 and col_area[j].count(var) == 0 and block_area[k].count(var) == 0);
                    row_area[i].insert(var);
                    col_area[j].insert(var);
                    block_area[k].insert(var);
                }
            }
#ifdef DEBUG
            rep(i, 9) {
                std::cout << "row_area[" << i << "]:";
                debug_set(row_area[i]);
            }
            rep(j, 9) {
                std::cout << "col_area[" << j << "]:";
                debug_set(col_area[j]);
            }
            rep(k, 9) {
                std::cout << "block_area[" << k << "]:";
                debug_set(block_area[k]);
            }
#endif
            return true;
        }

        bool check_constrains(int row, int col, vector<vector<char>>& board, set<char> row_area[], set<char> col_area[], set<char> block_area[], set<char> grids[9][9]) {
            auto& constrains = grids[row][col];
            if(constrains.size() == 1 && board[row][col] == '.') {
#ifdef DEBUG
                std::cout << "constrains updated at (" << row << "," << col << "):";
                debug_set(grids[row][col]);
#endif
                if(not update_board(row, col, *constrains.begin(), board, row_area, col_area, block_area, grids)) {
                    return false;
                }
            } else if(constrains.size() == 0) {
#ifdef DEBUG
                std::cout << "constrains empty at (" << row << "," << col << ")" << std::endl;
#endif
                return false;
            }
            return true;
        }

        bool update_board(int row , int col, char val, vector<vector<char>>& board, set<char> row_area[], set<char> col_area[], set<char> block_area[], set<char> grids[9][9]) {
            int block_id = get_block(row, col);
            board[row][col] = val;
            row_area[row].insert(val);
            col_area[col].insert(val);
            block_area[block_id].insert(val);
            rep(i, 9) {
                if(i != col) {
                    grids[row][i].erase(val);
                    if(not check_constrains(row, i, board, row_area, col_area, block_area, grids))
                        return false;
                }
                if(i != row) {
                    grids[i][col].erase(val);
                    if(not check_constrains(i, col, board, row_area, col_area, block_area, grids))
                        return false;
                }
            }
            for_in_block(block_id, block_row, block_col) {
                if(not (block_row == row and block_col == col)) {
                    grids[block_row][block_col].erase(val);
                    if(not check_constrains(block_row, block_col, board, row_area, col_area, block_area, grids)){
                        return false;
                    }
                }
            }
            return true;
        }

        bool get_constrains(vector<vector<char>>& board, set<char> row_area[], set<char> col_area[], set<char> block_area[], set<char> grids[9][9]) {
            static const set<char> all = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            foreach_grid(i, j) {
                int k = get_block(i, j);
                char var = board[i][j];
                set<char>& grid = grids[i][j];
                if(var == '.') { // eval posible alternatives
                    set<char> settled;
                    settled.insert(row_area[i].begin(), row_area[i].end());
                    settled.insert(col_area[j].begin(), col_area[j].end());
                    settled.insert(block_area[k].begin(), block_area[k].end());
                    set_difference(all.begin(), all.end(),
                            settled.begin(), settled.end(),
                            std::inserter(grid, grid.end()));
#ifdef DEBUG
                    std::cout << "constrains (" << i << "," << j << "):";
                    debug_set(grids[i][j]);
#endif
                } else{
                    grid.insert(var);
                }
            }

            //update after all constrains set
            foreach_grid(i, j) {
                if(board[i][j] == '.') {
                    if(not check_constrains(i, j, board, row_area, col_area, block_area, grids)) {
                        return false;
                    }
                }
            }
            return true;
        }

        bool update_unique_candidate(int constrains_cnt[], set<char>* last_occurred[], vector<vector<char>>& board, set<char> row_area[], set<char> col_area[], set<char> block_area[], set<char> grids[9][9]) {
            rep(iter, 9) {
                if(constrains_cnt[iter] == 1) {
                    int offset = last_occurred[iter] - (set<char>*)grids;
                    if(not update_board(offset/9, offset%9, iter + '1', board, row_area, col_area, block_area, grids)) {
                        return false;
                    }
                } 
            }
            return true;

        } 

        bool find_unique_candidate(vector<vector<char>>& board, set<char> row_area[], set<char> col_area[], set<char> block_area[], set<char> grids[9][9]) {
            rep(i, 9) {
                {
                    int constrains_cnt[9] = {};
                    set<char>* last_occurred[9] = {};
                    rep(j, 9) {
                        for(auto elem: grids[i][j]) {
                            constrains_cnt[elem - '1']++;
                            last_occurred[elem - '1'] = &grids[i][j];
                        } 
                    }
                    if(not update_unique_candidate(constrains_cnt, last_occurred, board, row_area, col_area, block_area, grids))
                        return false;
                }
                {
                    int constrains_cnt[9] = {};
                    set<char>* last_occurred[9] = {};
                    rep(j, 9) {
                        for(auto elem: grids[j][i]) {
                            constrains_cnt[elem - '1']++;
                            last_occurred[elem - '1'] = &grids[j][i];
                        } 
                    }
                    if(not update_unique_candidate(constrains_cnt, last_occurred, board, row_area, col_area, block_area, grids))
                        return false;
                }
                {
                    int constrains_cnt[9] = {};
                    set<char>* last_occurred[9] = {};
                    for_in_block(i, block_row, block_col) {
                        for(auto elem: grids[block_row][block_col]) {
                            constrains_cnt[elem - '1']++;
                            last_occurred[elem - '1'] = &grids[block_row][block_col];
                        } 
                    }
                    if(not update_unique_candidate(constrains_cnt, last_occurred, board, row_area, col_area, block_area, grids))
                        return false;
                }
            }
            return true;
        }

        bool try_solveSudoku(vector<vector<char>>& board) {
            // settled value in area
            set<char> row_area[9];
            set<char> col_area[9];
            set<char> block_area[9];
            if(not settled_values(board, row_area, col_area, block_area))
                return false;

            //avails of each grid
            set<char> grids[9][9];
            if(not get_constrains(board, row_area, col_area, block_area, grids))
                return false;

            if(not find_unique_candidate(board, row_area, col_area, block_area, grids))
                return false;

#ifdef DEBUG
            print_board(board);
#endif

            vector<vector<char>> new_board = board;
            foreach_grid(i, j) {
                auto grid = new_board[i][j];
                if(grid == '.') {
                    for(char elem : grids[i][j]) {
#ifdef DEBUG
                        std::cout << "try (" << i << "," << j << ") with elem=" << elem << std::endl;
#endif
                        new_board[i][j] = elem;
                        if(try_solveSudoku(new_board)) {
                            board = new_board; // update board
                            return true; 
                        }
                        new_board = board; //reset board
                    } 
                    return false;
                }
            }
            return true;
        }

        void solveSudoku(vector<vector<char>>& board) {
            if(try_solveSudoku(board)) {
                return;
            } else {
                std::cout << "solve failed!" << std::endl;
            }
        }
};

void print_board(const vector<vector<char>>& board) {
    for(auto row : board) {
        for(auto grid : row) {
            std::cout << grid << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    vector<const char*> input = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    //vector<const char*> input = {".34......","57...2.9.","9........","7...2984.","..9.15.3.",".2..8..51",".5.8.3...",".83....2.","..1..4..."};
    //vector<const char*> input = {"1.6.93..2","5..6...98",".....4.6.",".8.4.....","6...3...5", ".....9.3.", ".5.3.....","82...1..3","3..94.2.7"};
    vector<vector<char>> board;
    for(int i = 0; i < 9; ++i) {
        vector<char> row;
        for(int j = 0; j < 9; ++j) {
            row.push_back(input[i][j]);
        }
        board.push_back(row);
    }
    print_board(board);
    Solution().solveSudoku(board);
    print_board(board);
    return 0;
}
