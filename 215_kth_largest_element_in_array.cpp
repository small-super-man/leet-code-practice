//
// Created by tangchao on 2022/5/31.
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int nums_size = nums.size();

        default_random_engine e(time(nullptr));
        swap(nums[e() % nums_size], nums[0]);

        int i = 0;
        int j = nums_size - 1;
        while (i <= j) {
            while (i <= j && nums[0] <= nums[i]) {
                ++i;
            }
            while (i <= j && nums[0] > nums[j]) {
                --j;
            }

            if (i < j) {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }

        if (i == k) {
           return nums[0];
        }

        if (i > k) {
            swap(nums[0], nums[i - 1]);
            auto end_iter = nums.begin() + i - 1;
            vector<int> sub_nums(nums.begin(), end_iter);
            return findKthLargest(sub_nums, k);
        } else {
            vector<int> sub_nums(nums.begin() + i, nums.end());
            return findKthLargest(sub_nums, k - i);
        }
    }
};