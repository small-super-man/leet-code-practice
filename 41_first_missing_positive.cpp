//
// Created by tangchao on 2022/5/21.
//

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i) {
            while (nums[i] >= 1 && nums[i] <= nums_size && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < nums_size; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums_size + 1;
    }
};