//
// Created by tangchao on 2022/6/6.
//

class Solution {
public:
    void add(vector<int> &count, int idx) {
        while (idx <= 20001) {
            count[idx] += 1;
            idx += (idx & (-idx));
        }
    }

    int sum(vector<int> &count, int idx) {
        int sum = 0;
        while (idx > 0) {
           sum += count[idx];
           idx -= (idx & (-idx));
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(20002, 0);

        vector<int> result;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int mapped_num = nums[i] + 10001;
            result.push_back(sum(count, mapped_num - 1));
            add(count, mapped_num);
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

