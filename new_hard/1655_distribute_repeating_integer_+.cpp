//
// Created by tangchao on 2022/7/2.
//

class Solution {
public:
    /* wrong answer
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
       vector<int> count(1001, 0);
       for (auto &e : nums) {
            ++count[e];
       }

       sort(quantity.begin(), quantity.end());

       int i = quantity.size() - 1;
       while (i >= 0) {
           int candidate = -1;
           int diff = INT_MAX;
           int j = 0;
           while (j < 1001) {
                if (quantity[i] <= count[j] && count[j] - quantity[i] < diff) {
                    diff = count[j] - quantity[i];
                    candidate = j;
                }
                ++j;
           }
           if (candidate == -1) {
              break;
           }

           count[candidate] -= quantity[i];
           --i;
       }

       return i < 0;
    }
    */

    /*  backtracking but should eliminate the size of the frequency array
    bool _canDistribute(const vector<int> &quantity, int idx, vector<int> &count) {
        if (idx < 0) {
            return true;
        }

        for (int i = 0; i < count.size(); ++i) {
            if (count[i] >= quantity[idx]) {
                count[i] -= quantity[idx];
                bool ret = _canDistribute(quantity, idx - 1, count);
                if (ret) {
                    return true;
                }
                count[i] += quantity[idx];
            }
        }

        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
       vector<int> count(1001, 0);
       for (auto &e : nums) {
            ++count[e];
       }

       vector<int> clear_count;
       for (auto &e : count) {
            if (e) {
               clear_count.push_back(e);
            }
       }

       std::sort(quantity.begin(), quantity.end());

       return _canDistribute(quantity, quantity.size() - 1, clear_count);
    }
     */

    // dynamic programming;
    // distribute each frequency to corresponding quantity item;
    // dp(idx)(mask) : assign idx-n's frequency number to mask can fill all m bits ?
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        vector<int> count(1001, 0);
        for (auto &e : nums) {
            ++count[e];
        }
        vector<int> filter_count;
        for (auto &e : count) {
            if (e) {
                filter_count.push_back(e);
            }
        }

        int n = filter_count.size();
        int m = quantity.size();

        vector<int> sum_set((1 << m), 0);
        for (int k = 0; k < (1 << m); ++k) {
            for (int l = 0; l < m; ++l) {
                if (k & (1 << l)) {
                    sum_set[k] = sum_set[k & (~(1 << l))] + quantity[l];
                }
            }
        }

        // dp(i)(j) :
        // find all set that filer_count[i] can hold, and one of the set mask is mask#1;
        // if exists a mask#1 so that : dp(i + 1)(j | mask#1) = true, then dp(i)(j) == true, otherwise false;
        vector<vector<bool>> dp(n + 1, vector<bool>((1 << m), false));
        dp[n][(1 << m) - 1] = true;
        for (int i = n - 1; i >= 0; --i) {
            vector<int> candidate;
            for (int k = 0; k < (1 << m); ++k) {
                if (filter_count[i] >= sum_set[k]) {
                    candidate.push_back(k);
                }
            }

            for (int j = 0; j < (1 << m); ++j) {
                bool origin = dp[i][j];
                dp[i][j] = dp[i][j] || dp[i + 1][j];
                if (!dp[i][j]) {
                    for (auto &e : candidate) {
                        if (dp[i + 1][e | j]) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }

                if (!origin && dp[i][j]) {
                    // change all super set to true
                    for (int l = 0; l < (1 << m); ++l) {
                        // if 'l' contains j's all bits
                        if ((l & j) == j) {
                           dp[i][l] = true;
                        }
                    }
                }
            }
        }

        return dp[0][0];
    }

};