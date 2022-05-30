//
// Created by tangchao on 2022/5/21.
//

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row_set[9];
        unordered_set<char> column_set[9];
        unordered_set<char> matrix_set[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('.' == board[i][j]) {
                    continue;
                }

                auto iter = row_set[i].find(board[i][j]);
                if (iter != row_set[i].end()) {
                    return false;
                }
                row_set[i].insert(board[i][j]);

                iter = column_set[j].find(board[i][j]);
                if (iter != column_set[j].end()) {
                    return false;
                }
                column_set[j].insert(board[i][j]);

                int k = (i / 3 * 3 + j / 3);
                iter = matrix_set[k].find(board[i][j]);
                if (iter != matrix_set[k].end()) {
                    return false;
                }
                matrix_set[k].insert(board[i][j]);
            }
        }

        return true;
    }
};