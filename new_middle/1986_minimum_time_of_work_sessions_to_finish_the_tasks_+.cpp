//
// Created by tangchao on 2022/7/6.
//

class Solution {
public:
    int _calculate(const vector<int>& tasks, int sessionTime, int remain, int mask, vector<vector<int>> &dp) {
        int tasks_size = tasks.size();

        if (mask == 0) {
            return 1;
        }

        if (dp[mask][remain] != INT_MAX) {
            return dp[mask][remain];
        }

        int ans = INT_MAX;
        for (int i = 0; i < tasks_size; ++i) {
            if ((1 << i) & mask) {
                if (remain >= tasks[i]) {
                    ans = min(ans, _calculate(tasks, sessionTime, remain - tasks[i], mask & ~(1 << i), dp));
                } else {
                    ans = min(ans, 1 +_calculate(tasks, sessionTime, sessionTime - tasks[i], mask & ~(1 << i), dp));
                }
            }
        }

        return dp[mask][remain] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
       int tasks_size = tasks.size();
       vector<vector<int>> dp(1 << tasks_size, vector<int>(sessionTime + 1, INT_MAX));
       return _calculate(tasks, sessionTime, sessionTime, (1 << tasks_size) - 1, dp);
    }
};