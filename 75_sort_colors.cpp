//
// Created by tangchao on 2022/5/23.
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
       vector<int> count(3, 0);
       for (int i = 0; i < nums.size(); ++i) {
          ++count[nums[i]];
       }
       int i = 0;
       for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < count[j]; ++k) {
                nums[i++] = j;
            }
       }
    }
};

