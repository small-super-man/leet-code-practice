//
// Created by tangchao on 2022/5/29.
//

class Solution {
public:
    // o(n) time
    int findPeakElement(vector<int>& nums) {
       int nums_size = nums.size();

       if (nums_size == 1 && nums[0] == INT_MIN) {
          return 0;
       }

       for (int i = 0; i < nums_size; ++i) {
            int pre = INT_MIN;
            if (i > 0) {
               pre = nums[i - 1];
            }
            int post = INT_MIN;
            if (i < nums_size - 1) {
               post = nums[i + 1]
            }
            if (pre < nums[i] && post < nums[i]) {
               return i;
            }
       }

       return -1;
    }
};