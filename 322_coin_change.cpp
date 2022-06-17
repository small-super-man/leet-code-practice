//
// Created by tangchao on 2022/6/7.
//

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto &e : coins) {
                if (i >= e && dp[i - e] != -1) {
                    dp[i] = dp[i] == -1 ? dp[i - e] + 1 : min(dp[i], dp[i - e] + 1);
                }
            }
        }
        return dp[amount];
    }
};