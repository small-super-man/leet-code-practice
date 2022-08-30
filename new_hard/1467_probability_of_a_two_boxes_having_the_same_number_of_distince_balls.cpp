//
// Created by tangchao on 2022/6/30.
//

class Solution {
public:
    /*
     * time limit exceeded...
    void enumerate(const vector<int> &flagElements, int idx, int count[2], unordered_map<int, int> setMap[2], int &totalCount, int &distinctEqualCount) {
        if (count[0] == (flagElements.size() >> 1) || count[1] == (flagElements.size() >> 1)) {
            ++totalCount;
            int ii = count[0] == (flagElements.size() >> 1) ? 1 : 0;
            unordered_map<int, int> tmp_map;
            tmp_map = setMap[ii];
            for (int i = idx; i < flagElements.size(); ++i) {
                auto iter = tmp_map.find(flagElements[i]);
                if (iter == tmp_map.end()) {
                    auto tmp_pair = tmp_map.insert({flagElements[i], 0});
                    iter = tmp_pair.first;
                }
                ++iter->second;
            }
            if (setMap[ii ^ 1].size() == tmp_map.size()) {
                ++distinctEqualCount;
            }

            return;
        }

        for (int i = 0; i < 2; ++i) {
            ++count[i];
            auto iter = setMap[i].find(flagElements[idx]);
            if (iter == setMap[i].end()) {
                auto tmp_pair = setMap[i].insert({flagElements[idx], 0});
                iter = tmp_pair.first;
            }
            ++iter->second;

            enumerate(flagElements, idx + 1, count, setMap, totalCount, distinctEqualCount);

            if(--setMap[i][flagElements[idx]] == 0) {
                setMap[i].erase(flagElements[idx]);
            }
            --count[i];
        }
    }

    double getProbability(vector<int>& balls) {
        // flag the elements
        vector<int> flag_elements;
        for (int i = 1; i <= balls.size(); ++i) {
            for (int j = 0; j < balls[i - 1]; ++j) {
                flag_elements.push_back(i);
            }
        }

        // kind --> number in each set of two
        unordered_map<int, int> set_map[2];
        int count[2] = {0, 0};
        int  total_count = 0;
        int  distinct_equal_count = 0;
        enumerate(flag_elements, 0, count, set_map, total_count, distinct_equal_count);

        return static_cast<double>(distinct_equal_count) / total_count;
    }
    */

    // the answer from discussion
    void solve(const vector<int> &balls, int total, int idx, int k1, int k2, int n1, double p, const vector<vector<double>> &combinator, double &count, double &distinctCount) {
        if (idx >= balls.size()) {
            if (total == n1) {
                count += p;
                distinctCount += (k1 == k2 ? p : 0);
            }
            return;
        }

        for (int i = 0; i <= balls[idx]; ++i) {
            if (n1 + i > total) {
                break;
            }
            int k11 = (i != 0 ? 1 : 0) + k1;
            int k22 = (i != balls[idx] ? 1 : 0) + k2;
            solve(balls, total, idx + 1, k11, k22, n1 + i, p * combinator[balls[idx]][i], combinator, count, distinctCount);
        }
    }

    double getProbability(vector<int>& balls) {
        vector<vector<double>> combinator(7, vector<double>(7, 0));
        for (int i = 0; i < 7; ++i) {
            combinator[i][0] = combinator[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                combinator[i][j] = combinator[i - 1][j - 1] + combinator[i - 1][j];
            }
        }

        int total = 0;
        for (auto &e : balls) {
            total += e;
        }
        total /= 2;

        double count = 0;
        double equal_distinct_count = 0;
        solve(balls, total, 0, 0, 0, 0, 1, combinator, count, equal_distinct_count);

        return equal_distinct_count / count;
    }
};

