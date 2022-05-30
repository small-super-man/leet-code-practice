//
// Created by tangchao on 2022/5/23.
//

class Solution {
public:
    bool _dfs(const vector<vector<char>> &board, const string &word, vector<vector<bool>> &visited, int i, int j, int s) {
        static vector<pair<int, int>> steps({make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)});

        if (s >= word.size()) {
            return true;
        }

        if (board[i][j] != word[s]) {
            return false;
        }

        if (s + 1 >= word.size()) {
            return true;
        }

        visited[i][j] = true;

        for (int k = 0; k < 4; ++k) {
            int ii = i + steps[k].first;
            int jj = j + steps[k].second;
            if (ii >= board.size() || jj >= board[0].size() || ii < 0 || jj < 0 || visited[ii][jj]) {
                continue;
            }
            bool sub_ret = _dfs(board,  word, visited, ii, jj, s + 1);
            if (sub_ret) {
                return true;
            }
        }

        visited[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row_size = board.size();
        int column_size = board[0].size();
        vector<vector<bool>> visited(row_size, vector<bool>(column_size, false));
        for  (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                if (_dfs(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};