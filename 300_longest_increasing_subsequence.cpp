//
// Created by tangchao on 2022/6/6.
//

class Solution {
public:
    // dp(i) = max(1, dp(j) + 1) where nums[j] > nums[i]
    int lengthOfLIS(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> dp(nums_size, 0);
        int max_len = 0;
        for (int i = nums_size - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < nums_size; ++j) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            if (max_len < dp[i]) {
                max_len = dp[i];
            }
        }

        return max_len;
    }
};