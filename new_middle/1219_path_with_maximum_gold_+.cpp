//
// Created by tangchao on 2022/6/28.
//

class Solution {
public:
    void dfs(const vector<vector<int>>& grid, int x, int y, std::vector<std::vector<bool>> &visited, int &currentNum, int &maxNum) {
        static vector<pair<int, int>> steps{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int row_size = grid.size();
        int column_size = grid[0].size();

        visited[x][y] = true;
        currentNum += gridp[x][y];

        bool has_moved = false;
        for (int i = 0; i < 4; ++i) {
            int xx = x + steps[i].first;
            int yy = y + steps[i].second;
            if (xx >= 0 && xx < row_size && yy >= 0 && yy < column_size && !visited[xx][yy] && grid[xx][yy] > 0) {
                dfs(grid, xx, yy, visited, currentNum, maxNum);
                has_moved = true;
            }
        }

        if (!has_moved && maxNum < currentNum) {
            maxNum = currentNum;
        }

        visited[x][y] = false;
        currentNum -= gridp[x][y];
    }

    int getMaximumGold(vector<vector<int>>& grid) {
       int row_size = grid.size();
       int column_size = grid[0].size();

       std::vector<std::vector<bool>> visited(row_size, vector<bool>(column_size, false));
       int max_gold_num = 0;
       int current_gold_num = 0;
       for (int i = 0; i < row_size; ++i) {
           for (int j = 0; j < column_size; ++j) {
                if (grid[i][j] > 0) {
                    dfs(grid, i, j, visited, current_gold_num, max_gold_num);
                }
           }
       }

       return max_gold_num;
    }
};