//
// Created by tangchao on 2022/5/30.
//

class Solution {
public:
    // o(k) space complexity
    /*
    void rotate(vector<int>& nums, int k) {
       int nums_size = nums.size();
       int kk = k % nums_size;
       vector<int> tmp;
       for (int i = nums_size - kk; i < nums_size;  ++i) {
            tmp.push_back(nums[i]);
       }

       for (int i = nums_size - 1, j = nums_size - kk - 1; j >= 0; --i, --j) {
            nums[i] = nums[j];
       }

       for (int i = 0; i < kk; ++i) {
            nums[i] = tmp[i];
       }
    }
     */

    // O(1) space complexity
    void rotate(vector<int>& nums, int k) {
        int nums_size = nums.size();
        int kk = k % nums_size;

        int change_count = 0;
        int start = 0;

        while (change_count < nums_size) {
            int next = (start + kk) % nums_size;
            int tmp = nums[start];
            while (next != start) {
                swap(nums[next], tmp);
                next = (next + kk) % nums_size;
                ++change_count;
            }
            nums[next] = tmp;
            ++change_count;

            start = (start + 1) % nums_size;
        }
    }
};
