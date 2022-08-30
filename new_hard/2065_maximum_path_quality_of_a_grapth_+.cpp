//
// Created by tangchao on 2022/7/11.
//

class Solution {
public:
    void dfs(const vector<int>& values, const vector<vector<pair<int, int>>> &table, int maxTime, int idx, unordered_map<int, int> &frequency, int &currentTime, int currentSum, int &maxSum) {
        if (frequency.count(idx) == 0) {
           frequency.insert({idx, 0});
        }
        ++frequency[idx];

        if (frequency[idx] == 1) {
            currentSum += values[idx];
        }

        if (idx == 0) {
            maxSum = max(maxSum, currentSum);
        }

        for (auto &e : table[idx]) {
            if (currentTime + e.second <= maxTime) {
                dfs(values, table, maxTime, e.first, frequency, currentTime + e.second, currentSum, maxSum);
            }
        }

        if (--frequency[idx] == 0) {
            frequency.erase(idx);
            currentSum -= values[idx];
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
       int values_size = values.size();
       vector<vector<pair<int, int>>> table(values_size, vector<pair<int, int>>());
       for (auto &e : edges) {
            table[e[0]].push_back({e[1], e[2]});
            table[e[1]].push_back({e[0], e[2]});
       }

       unordered_map<int, int> frequency;
       int max_sum = INT_MIN;
       int current_time = 0;
       int current_sum = 0;
       dfs(values, table, maxTime, 0, frequency, current_time, current_sum, max_sum);
       return max_sum;
    }
};