//
// Created by tangchao on 2022/7/3.
//

class Solution {
public:

    int minimumTimeRequired(vector<int>& jobs, int k) {
       // dp(i)(mask) : 'mask' allocated job if set '1'; i~k worker;
       // dp(i)(mask) : enumerate all possible job set which can be allocated to  worker i
       // mask#1, dp(i)(mask) = minimum of all possible mask#1 set : min(sum(mask#1), dp(i + 1)(mask | mask#1))
       // time complexity : k  * 2 ^ (jobs.size())

       int jobs_size = jobs.size();
       vector<vector<int>> dp(k + 1, vector<int>(1 << jobs_size, INT_MAX));
       dp[k][(1 << jobs_size) - 1] = 0;

       vector<int> value_table(1 << jobs_size, 0);
       for (int i = 0; i < (1 << jobs_size); ++i) {
            for (int j = 0; j < jobs_size; ++j) {
                if (i  & (1 << j)) {
                    value_table[i] += jobs[j];
                }
            }
       }

       int global_mask = (1 << jobs_size) - 1;

       for (int i = k - 1; i >= 0; --i) {
            for (int j = 0; j < (1 << jobs_size); ++j) {
                int mask0 = global_mask & ~(j);
                /*
                for (int k = 0; k < (1 << jobs_size); ++k) {
                    if ((k | mask0) == mask0) {
                        dp[i][j] = min(dp[i][j], max(value_table[k], dp[i + 1][k | j]));
                    }
                }
                */
                for (auto l = mask0; l; l = (l - 1) & mask0) {
                    dp[i][j] = min(dp[i][j], max(value_table[l], dp[i + 1][l | j]));
                }
            }
       }

       return dp[0][0];
    }
};