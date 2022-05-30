//
// Created by tangchao on 2022/5/23.
//

class Solution {
public:
    /*
    bool canJump(vector<int>& nums) {
        int nums_size = nums.size();
        vector<bool> can_reach(nums_size, false);
        can_reach[nums_size - 1] = true;
        for (int i = nums_size - 2; i >= 0; --i) {
            if (i + nums[i] >= nums_size - 1) {
                can_reach[i] = true;
                continue;
            }

            for (int j = 1; j <= nums[i]; ++j) {
                if (can_reach[i + j]) {
                    can_reach[i] = true;
                    break;
                }
            }
        }

        return can_reach[0];
    }
    */

    bool canJump(vector<int>& nums) {
       int nums_size = nums.size();
       int can_reach = 0;
       int i = 0;
       while (i <= can_reach) {
            int tmp_reach = i + nums[i];
            if (tmp_reach >= nums_size - 1) {
               return true;
            }

            if (tmp_reach > can_reach) {
                can_reach = tmp_reach;
            }

            ++i;
       }

       return can_reach >= nums_size - 1;
    }
};