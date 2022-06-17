//
// Created by tangchao on 2022/6/3.
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int nums_size = nums.size();

        int l = 1;
        int h = nums_size - 1;
        while (l < h) {
            int m = (l + h) / 2;
            int sum = 0;
            for (auto &e : nums) {
                if (e <= m) {
                    ++sum;
                }
            }

            if (sum > m) {
                h = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};

