//
// Created by tangchao on 2022/6/27.
//

class Solution {
public:
    void dfs(const vector<vector<int>>& grid, int x, int y, const vector<int> &end, int noObstacleNum, vector<vector<bool>> &visited, int &current_visited, int &unique_path_num) {
        static vector<pair<int, int>> steps({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        int row_size = grid.size();
        int column_size = grid[0].size();

        visited[x][y] = true;
        ++current_visited;
        if (x == end[0] && y == end[1]) {
            if (current_visited == noObstacleNum) {
                ++unique_path_num;
            }

            visited[x][y] = false;
            --current_visited;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int xx = x + steps[i].first;
            int yy = y + steps[i].second;

            if (xx >= 0 && xx < row_size && yy >= 0 && yy < column_size && -1 != grid[xx][yy] && !visited[xx][yy]) {
                dfs(grid, xx, yy, end, noObstacleNum, visited, current_visited, unique_path_num);
            }
        }

        --current_visited;
        visited[x][y] = false;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int row_size = grid.size();
        int column_size = grid[0].size();

        vector<int> start_point(2, 0);
        vector<int> end_point(2, 0);
        int obstacle_num = 0;
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                if (grid[i][j] == 1) {
                    start_point[0] = i;
                    start_point[1] = j;
                } else if (grid[i][j] == 2) {
                    end_point[0] = i;
                    end_point[1] = j;
                } else if (grid[i][j] == -1) {
                    ++obstacle_num;
                }
            }
        }
        int no_obstacle_num = row_size * column_size - obstacle_num;

        int unique_path_num = 0;
        vector<vector<bool>> visited(row_size, vector<bool>(column_size, false));
        int current_visited_num = 0;
        dfs(grid, start_point[0], start_point[1], end_point, no_obstacle_num, visited, current_visited_num, unique_path_num);

        return unique_path_num;
    }
};