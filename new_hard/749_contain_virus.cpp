class Solution {
public:
    const vector<pair<int, int>> steps{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(const vector<vector<int>> &infected, vector<vector<bool>> &fended, int row_idx, int column_idx, vector<vector<bool>> &visited, vector<pair<int, int>> &block) {
        visited[row_idx][column_idx] = true;
        block.emplace_back(row_idx, column_idx);

        int row_size = infected.size();
        int column_size = infected[0].size();

        for (int i = 0; i < 4; ++i) {
            int xx = row_idx + steps[i].first;
            int yy = column_idx + steps[i].second;

            if (xx >= 0 && xx < row_size && yy >= 0 && yy < column_size && infected[xx][yy] && !fended[xx][yy] && !visited[xx][yy]) {
                dfs(infected, fended, xx, yy, visited, block);
            }
        }
    }

    vector<pair<int, int>> generate(vector<vector<int>> &isInfected, vector<pair<int, int>> &block, pair<int, int> &index) {
        int row_size = isInfected.size();
        int column_size = isInfected[0].size();

        set<pair<int, int>> next_block;
        int contaminated_num = 0;
        int fender_num = 0;
        for (auto &e : block) {
            for (int i = 0; i < 4; ++i) {
                int xx = e.first + steps[i].first;
                int yy = e.second + steps[i].second;

                if (xx >= 0 && xx < row_size && yy >= 0 && yy < column_size) {
                    if (isInfected[xx][yy]) {
                        continue;
                    }

                    ++fender_num;

                    pair<int, int> new_item(xx, yy);
                    if (!next_block.count(new_item)) {
                        ++contaminated_num;
                        next_block.insert(new_item);
                    }
                }
            }
        }

        index.first = contaminated_num;
        index.second = fender_num;

        vector<pair<int, int>> new_vec(next_block.begin(), next_block.end());
        return new_vec;
    }

    int containVirus(vector<vector<int>>& isInfected)
    {
        int row_size = isInfected.size();
        int column_size = isInfected[0].size();

        vector<vector<bool>> fended(row_size, vector<bool>(column_size, false));
        int total_fender_count = 0;
        while (true) {
            vector<vector<pair<int, int>>>  blocks;
            vector<vector<bool>> visited(row_size, vector<bool>(column_size, false));

            for (int i = 0; i < row_size; ++i) {
                for (int j = 0; j < column_size; ++j) {
                    if (isInfected[i][j] && !visited[i][j] && !fended[i][j]) {
                        vector<pair<int, int>> infected_block;
                        dfs(isInfected, fended, i, j, visited, infected_block);
                        blocks.push_back(infected_block);
                    }
                }
            }

            if (blocks.empty()) {
                break;
            }

            vector<pair<int, int>> index(blocks.size(), {0, 0});
            auto cmp = [&index](const int &one, const int &two) {
              return index[one].first < index[two].first;
            };
            priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
            vector<vector<pair<int, int>>>  next_blocks(blocks.size(), vector<pair<int, int>>());
            for (int i = 0; i < blocks.size(); ++i) {
                next_blocks[i] = generate(isInfected, blocks[i], index[i]);
                heap.push(i);
            }
            auto top = heap.top();
            heap.pop();
            for (auto &e : blocks[top]) {
                fended[e.first][e.second] = true;
            }
            total_fender_count += index[top].second;

            while (!heap.empty()) {
                auto idx = heap.top();
                heap.pop();
                for (auto &e : next_blocks[idx]) {
                    isInfected[e.first][e.second] = 1;
                }
            }
        }

        return total_fender_count;
    }
};