//
// Created by tangchao on 2022/5/30.
//

class Solution {
public:
    void _dfs(const vector<vector<char>>& grid, vector<vector<bool>> &visited, int x, int y) {
        static vector<pair<int, int>> steps({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

        int row_size = grid.size();
        int column_size = grid[0].size();
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int xx = x + steps[i].first;
            int yy = y + steps[i].second;
            if (xx >= 0 && xx < row_size && yy >= 0 && yy < column_size && '1' == grid[xx][yy] && !visited[xx][yy]) {
                _dfs(grid, visited, xx, yy);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row_size = grid.size();
        int column_size = grid[0].size();
        int island_num = 0;
        vector<vector<bool>> visited(row_size, vector<bool>(column_size, false));
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                if ('1' == grid[i][j] && !visited[i][j]) {
                    ++island_num;
                    _dfs(grid, visited, i, j);
                }
            }
        }
        return island_num;
    }
};

