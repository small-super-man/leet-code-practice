//
// Created by tangchao on 2022/5/29.
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int nums_size = nums.size();
        int max_result = INT_MIN;
        vector<int> max_product(nums_size, 0);
        vector<int> min_product(nums_size, 0);
        for (int i = 0; i < nums_size; ++i) {
            if (0 == nums[i]) {
                max_product[i] = min_product[i] = 0;
            } else if (nums[i] > 0) {
                max_product[i] = nums[i];
                min_product[i] = nums[i];
                if (i > 0) {
                    max_product[i] = max(max_product[i], nums[i] * max_product[i - 1]);
                    min_product[i] = min(min_product[i], nums[i] * min_product[i - 1]);
                }
            } else {
                max_product[i] = nums[i];
                min_product[i] = nums[i];
                if (i > 0) {
                    max_product[i] = max(max_product[i], nums[i] * min_product[i - 1]);
                    min_product[i] = min(min_product[i], nums[i] * max_product[i - 1]);
                }
            }

            if (max_result < max_product[i]) {
               max_result = max_product[i];
            }
        }

        return max_result;
    }
};