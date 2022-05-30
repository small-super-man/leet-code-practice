//
// Created by tangchao on 2022/5/30.
//

class Solution {
public:
    int rob(vector<int>& nums) {
       if (nums.empty()) {
          return 0;
       }
       if (1 == nums.size()) {
          return nums[0];
       }
       if (2 == nums.size()) {
          return max(nums[0], nums[1]);
       }

       int pre_2 = nums[nums.size() - 1];
       int pre_1 = max(nums[nums.size() - 2], pre_2);
       for (int i = nums.size() - 3; i >= 0; --i) {
            int current = max(nums[i] + pre_2, pre_1);
            pre_2 = pre_1;
            pre_1 = current;
       }

       return pre_1;
    }
};