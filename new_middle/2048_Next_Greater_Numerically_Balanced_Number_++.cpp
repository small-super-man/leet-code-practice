//
// Created by tangchao on 2022/7/10.
//

class Solution {
public:
    void evaluate(int idx, int aim, int currentSum, vector<int> &path, vector<vector<int>> &candidates) {
        if (aim == currentSum) {
            candidates.push_back(path);
            return;
        }

        if (idx > 9) {
            return;
        }

        if (idx + currentSum <= aim) {
            path.push_back(idx);
            evaluate(idx + 1, aim, currentSum + idx, path, candidates);
            path.pop_back();
        }

        evaluate(idx + 1, aim, currentSum, path, candidates);
    }

    void permutation(int n, vector<int> &candidate, int idx, int &current, int &result) {
        if (idx >= candidate.size()) {
            if (current > n) {
                result = min(current, result);
            }
            return;
        }

        unordered_set<int> filter;
        for (int i = idx; i < candidate.size(); ++i) {
            if (filter.count(candidate[i]) == 0) {
                filter.insert(candidate[i]);
                swap(candidate[i], candidate[idx]);
                current += pow(10, candidate.size() - 1 - idx) * candidate[idx];
                permutation(n, candidate, idx + 1, current, result);
                current -= pow(10, candidate.size() - 1 - idx) * candidate[idx];
                swap(candidate[i], candidate[idx]);
            }
        }
    }

    int nextBeautifulNumber(int n) {
        int loc_num = 0;
        int nn = n;
        while (nn) {
            ++loc_num;
            nn /= 10;
        }

        int limit = 0;
        for (int i = 0; i < loc_num; ++i) {
            limit += pow(10, i) * loc_num;
        }

        if (limit <= n) {
            ++loc_num;
        }

        vector<vector<int>> candidates;
        vector<int> path;
        evaluate(1, loc_num, 0, path, candidates);

        int result = INT_MAX;
        for (auto &e : candidates) {
            vector<int> tmp;
            for (auto &ee : e) {
                for (int i = 0; i < ee; ++i) {
                    tmp.push_back(ee);
                }
            }
            int current = 0;
            int tmp_result = INT_MAX;
            permutation(n, tmp, 0, current, tmp_result);
            result = min(tmp_result, result);
        }

        return result;
    }
};