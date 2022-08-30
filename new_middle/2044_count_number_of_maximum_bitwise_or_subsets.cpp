//
// Created by tangchao on 2022/7/9.
//

class Solution {
public:
    void _calculate(const vector<int>& nums, int maximum, int idx, int mask, int &count) {
        if (idx >= nums.size()) {
           if (mask == maximum) {
                ++count;
           }
           return;
        }

        _calculate(nums, maximum, idx + 1, mask, count);
        _calculate(nums, maximum, idx + 1, mask | nums[idx], count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maximum = 0;
        for (auto &e : nums) {
            maximum |= e;
        }

        int count = 0;
        int mask = 0;
        _calculate(nums, maximum, 0, mask, count);
        return count;
    }
};