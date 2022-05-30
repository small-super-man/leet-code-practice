//
// Created by tangchao on 2022/5/26.
//

class Solution {
public:
    // 从每一个边缘的O节点开始进行dfs, 标记好所有访问过的O节点
    // 遍历整个board，把所有没访问过的O节点调整为X
    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, int x, int y) {
        static vector<pair<int, int>> steps({{1, 0}, {0, 1}, {0, -1}, {-1, 0}});

        int row_size = board.size();
        int column_size = board[0].size();

        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int xx = x + steps[i].first;
            int yy = y + steps[i].second;
            if (xx >= 0 && xx < row_size && yy >= 0 && yy < column_size && 'O' == board[xx][yy] && !visited[xx][yy]) {
                dfs(board, visited, xx, yy);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
       int row_size = board.size();
       int column_size = board[0].size();
       vector<vector<bool>> visited(row_size, vector<bool>(column_size, false));

       if (row_size == 1 && column_size == 1 && board[0][0] == 'O') {
           visited[0][0] = true;
       }

       for (int j = 0; j < column_size - 1; ++j) {
            if (!visited[0][j] && 'O' == board[0][j]) {
                dfs(board, visited, 0, j);
            }
       }
       for (int j = 0; j < row_size - 1; ++j) {
           if (!visited[j][column_size - 1]  && 'O' == board[j][column_size - 1]) {
               dfs(board, visited, j, column_size - 1);
           }
       }
       for (int j = column_size - 1; j > 0; --j) {
           if (!visited[row_size - 1][j] && 'O' == board[row_size - 1][j]) {
               dfs(board, visited, row_size - 1, j);
           }
       }
       for (int j = row_size - 1; j > 0; --j) {
           if (!visited[j][0] && 'O' == board[j][0]) {
               dfs(board, visited, j, 0);
           }
       }

       for (int i = 0; i < row_size; ++i) {
           for (int j = 0; j < column_size; ++j) {
                if ('O' == board[i][j] && !visited[i][j]) {
                    board[i][j] = 'X';
                }
           }
       }
    }
};