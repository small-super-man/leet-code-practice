//
// Created by tangchao on 2022/5/21.
//

// O(log(n))
class Solution {
public:
    int _find(vector<int>& nums, int start_pos, int end_pos, int target) {
        if (start_pos > end_pos) {
            return -1;
        }

        // binary search
        int l = start_pos;
        int h = end_pos;
        while (l <= h) {
            int m = (l + h) / 2;
            if (target == nums[m]) {
                return m;
            }

            if (target > nums[m]) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        // find the join point;
        int l = 0;
        int h = nums.size() - 1;
        while (l < h) {
            int m = (l + h) / 2;
            if (nums[m] < nums[h]) {
                h = m;
            } else {
                l = m + 1;
            }
        }

        // find target in each partition
        int firt_partition_find = _find(nums, 0, l - 1, target);
        int second_partition_find = _find(nums, l, nums.size() - 1, target);

        if (-1 != firt_partition_find) {
           return firt_partition_find;
        }

        if (-1 != second_partition_find) {
            return second_partition_find;
        }

        return -1;
    }
};

