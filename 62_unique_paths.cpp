//
// Created by tangchao on 2022/5/23.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp[2] = {vector<int>(n, 1), vector<int>(n, 1)};
        int pre_idx = 0;
        int current_idx = 1;
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (j == n - 1) {
                    dp[current_idx][j] = 1;
                } else {
                    dp[current_idx][j] = dp[current_idx][j + 1] + dp[pre_idx][j];
                }
            }

            swap(pre_idx, current_idx);
        }

        return dp[pre_idx][0];
    }
};