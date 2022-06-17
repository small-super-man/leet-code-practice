//
// Created by tangchao on 2022/6/3.
//

class Solution {
public:
    // dynamic programming
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = INT_MAX;
            for (int sq = 1; sq * sq <= i; ++sq) {
               dp[i] = min(dp[i], 1 + dp[i - sq * sq]);
            }
        }

        return dp[n];
    }
};
