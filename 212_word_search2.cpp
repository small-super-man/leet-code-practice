//
// Created by tangchao on 2022/5/31.
//

class Solution {
public:
    void _dfs(vector<vector<char>>& board, const unordered_set<string> &wordSet, vector<vector<bool>> &visited, unordered_set<string> &result, int maxSize, int x, int y, string &path) {
       static vector<pair<int, int>> steps({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

       visited[x][y] = true;
       path.push_back(board[x][y]);

       if (wordSet.count(path)) {
          result.insert(path);
       }

       if (path.size() < maxSize) {
           for (int i = 0; i < 4; ++i) {
                int xx = x + steps[i].first;
                int yy = y + steps[i].second;
                if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size() && !visited[xx][yy]) {
                    _dfs(board, wordSet, visited, result, maxSize, xx, yy, path);
                }
           }
       }

       path.pop_back();
       visited[x][y] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int max_word_size = 0;
        int count[26] = {0};
        for (auto &e : words) {
            if (max_word_size < e.size()) {
                max_word_size = e.size();
            }
            ++count[e[0] - 'a'];
        }
        unordered_set<string> word_set(words.begin(), words.end());
        unordered_set<string> result;
        int row_size = board.size();
        int column_size = board[0].size();
        vector<vector<bool>> visited(row_size, vector<bool>(column_size, false));
        string path;
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                if (!count[board[i][j] - 'a']) {
                    continue;
                }
                _dfs(board, word_set, visited, result, max_word_size, i, j, path);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};
