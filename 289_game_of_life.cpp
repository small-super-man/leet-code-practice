//
// Created by tangchao on 2022/6/3.
//

class Solution {
public:
    // 00 01
    // 10 11
    void gameOfLife(vector<vector<int>>& board) {
        int row_size = board.size();
        int column_size = board[0].size();
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                int num = 0;
                if (board[i][j]) {
                    board[i][j] = 2;
                }

                if (j - 1 >= 0) {
                    num += ((board[i][j - 1] >> 1) & 1);
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    num += ((board[i - 1][j - 1] >> 1) & 1);
                }

                if (i - 1 >= 0) {
                    num += ((board[i - 1][j] >> 1) & 1);
                }

                if (i - 1 >= 0 && j + 1 < column_size) {
                    num += ((board[i - 1][j + 1] >> 1) & 1);
                }

                if (j + 1 < column_size) {
                    num += board[i][j + 1];
                }

                if (i + 1 < row_size && j + 1 < column_size) {
                    num += board[i + 1][j + 1];
                }

                if (i + 1 < row_size) {
                    num += board[i + 1][j];
                }

                if (i + 1 < row_size && j - 1 >= 0) {
                    num += board[i + 1][j - 1];
                }

                if (board[i][j]) {
                    if (num >= 2 && num <= 3) {
                        board[i][j] = (board[i][j] | 1);
                    }
                } else {
                    if (num == 3) {
                        board[i][j] = (board[i][j] | 1);
                    }
                }
            }
        }

        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                board[i][j] = (board[i][j] & 1);
            }
        }
    }
};