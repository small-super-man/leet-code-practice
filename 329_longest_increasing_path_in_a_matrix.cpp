//
// Created by tangchao on 2022/6/6.
//

class Solution {
public:
    int dfs(const vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &visited, vector<vector<bool>> &visited2) {
        static vector<pair<int, int>> steps({{-1, 0}, {1, 0}, {0, 1}, {0, -1}});

        visited2[x][y] = true;

        int max_len = 1;
        for (int i = 0; i < 4; ++i) {
            int xx = x + steps[i].first;
            int yy = y + steps[i].second;
            if (xx >= 0 && xx < matrix.size() && yy >= 0 && yy < matrix[0].size() && matrix[x][y] < matrix[xx][yy]) {
                if (visited[xx][yy]) {
                    max_len = max(max_len, visited[xx][yy] + 1);
                } else {
                    int tmp_len = dfs(matrix, xx, yy, visited, visited2) + 1;
                    if (tmp_len > max_len) {
                        max_len = tmp_len;
                    }
                }
            }
        }

        visited2[x][y] = false;
        visited[x][y] = max_len;
        return max_len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int row_size = matrix.size();
       int column_size = matrix[0].size();

       vector<vector<int>> visited(row_size, vector<int>(column_size, 0));
       vector<vector<bool>> visited2(row_size, vector<bool>(column_size, false));
       int max_len = 0;
       for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                if (!visited[i][j]) {
                    int max_incr_len = dfs(matrix, i, j, visited, visited2);
                    if (max_incr_len > max_len) {
                        max_len = max_incr_len;
                    }
                }
            }
       }

       return max_len;
    }
};
