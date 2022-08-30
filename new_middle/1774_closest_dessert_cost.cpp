//
// Created by tangchao on 2022/7/4.
//

class Solution {
public:
    // this problem should be coding with more care!!!
    void _calculate(const vector<int>& toppingCosts, int idx, int target, vector<vector<int>> &memo) {
        int topping_size = toppingCosts.size();
        if (idx >= topping_size) {
            return 0;
        }

        if (memo[idx][target] != INT_MAX) {
           return memo[idx][target];
        }

        int result = 0;
        int res_abs = target;
        int sum = 0;
        for (int n = 0; n < 3; ++n) {
           int current = sum;
           if (current < target) {
                current += _calculate(toppingCosts, idx + 1, target - current, memo);
           }

           int current_abs = abs(current - target);
           if (current_abs < res_abs || (current_abs == res_abs && current < result)) {
                result = current;
                res_abs = current_abs;
           }

           sum += toppingCosts[idx];
        }

        return memo[idx][target] = result;
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int base_size = baseCosts.size();

        vector<vector<int>> memo(toppingCosts.size(), vector<int>(target, INT_MAX));

        int result = 0;
        int res_abs = INT_MAX;
        for (int i = 0; i < base_size; ++i) {
            int current = baseCosts[i];
            if (current < target) {
               current += _calculate(toppingCosts, 0, target - current, memo);
            }

            int current_abs = abs(current - target);
            if (current_abs < res_abs || (current_abs == res_abs && current < result)) {
                result = current;
                res_abs = current_abs;
            }
        }

        return result;
    }
};