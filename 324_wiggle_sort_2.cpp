//
// Created by tangchao on 2022/6/7.
//

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 2) {
           return;
        }

        std::sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        int border = (nums_size + 1) / 2;

        int ok_count = 0;
        int loc = 0;
        while (ok_count < nums_size) {
            int aimed_loc = (loc >= border ? (2 * (loc - border + 1) - 1) : (2 * loc));

            while (loc != aimed_loc) {
                int next_loc = (aimed_loc >= border ? (2 * (aimed_loc - border + 1) - 1) : (2 * aimed_loc));
                swap(nums[aimed_loc], nums[loc]);
                aimed_loc = next_loc;
                ok_count++;
            }
            ++ok_count;

            ++loc;
        }

    }
};
