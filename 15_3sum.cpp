//
// Created by tangchao on 2022/5/18.
//

class Solution {
public:
    int next(const vector<int>& nums, int i) {
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) {
            ++j;
        }
        return j;
    }

    int pre(const vector<int>& nums, int i) {
        int j = i - 1;
        while (j >= 0 && nums[j] == nums[i]) {
            --j;
        }
        return j;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
       if (nums.size() < 3) {
            return result;
       }

       std::sort(nums.begin(), nums.end());
       int i = 0;
       while (i < nums.size() - 2) {
            vector<int> tmp_vec(3, nums[i]);
            int remain = 0 - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] < remain) {
                    j = next(nums, j);
                } else if (nums[j] + nums[k] > remain) {
                    k = pre(nums, k);
                } else {
                    tmp_vec[1] = nums[j];
                    tmp_vec[2] = nums[k];
                    result.push_back(tmp_vec);
                    j = next(nums, j);
                    k = pre(nums, k);
                }
            }

            i = next(nums, i);
       }
       return result;
    }
};
