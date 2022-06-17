//
// Created by tangchao on 2022/6/3.
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int current_product = 1;
        vector<int> prefix_product;
        for (auto &e : nums) {
            current_product *= e;
            prefix_product.push_back(current_product);
        }

        current_product = 1;
        vector<int> post_product(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            current_product *= nums[i];
            post_product[i] = current_product;
        }

        vector<int> result(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            int pre = 1;
            if (i > 0) {
                pre = prefix_product[i - 1];
            }
            int post = 1;
            if (i < nums.size() - 1) {
                post = post_product[i + 1];
            }

            result[i] = pre * post;
        }

        return result;
    }
};