//
// Created by tangchao on 2022/7/4.
//

class Solution {
public:
    int _gcd(int x, int y) {
       static map<pair<int, int>, int> memo;
       if (x > y) {
          swap(x, y);
       }

       auto tmp_pair = make_pair(x, y);
       if (memo.count(tmp_pair)) {
            return memo[tmp_pair];
       }

       int r = y % x;
       while (r) {
           y = x;
           x = r;
           r = y % r;
       }

       return x;
    }

    int _calculate(vector<int> &nums, int idx, int mask, int n, vector<vector<int>> &dp) {
        if  (mask == (1 << n) - 1) {
            assert(idx == n / 2 + 1);
            return  0;
        }

        if (dp[idx][mask]) {
            return dp[idx][mask];
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
           for (int j = i + 1; j < n; ++j) {
                if (0 == ((1 << i) & mask) && 0 == ((1 << j) & mask)) {
                    int tmp_result = idx * gcd(nums[i], nums[j]) + _calculate(nums, idx + 1, mask | (1 << i) | (1 << j), n, dp);
                    if (tmp_result > result) {
                       result = tmp_result;
                    }
                }
           }
        }

        return dp[idx][mask] = result;
    }

    // dp(idx)(mask) : enumerate all possible mask#1 corresponding gcd#1, dpp(idx)(mask) = max(idx * gcd(mask#1) + dp(idx + 1)(mask | mask#1))
    int maxScore(vector<int>& nums) {
       vector<vector<int>> dp(nums.size() + 1, vector<int>(1 << nums.size(), 0));
       return _calculate(nums, 1, 0, nums.size(), dp);
    }
};