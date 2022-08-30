//
// Created by tangchao on 2022/7/6.
//

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> nums_set;
        for (auto &e : nums) {
            int ee = std::stoi(e, nullptr, 2);
            nums_set.insert(ee);
        }

        int nums_size = nums.size();
        int result_num = 0;
        for (int i = 0; i < (1 << nums_size); ++i) {
            if (0 == nums_set.count(i)) {
                result_num = i;
                break;
            }
        }

        string result;
        while (result_num) {
            result.push_back((result_num & 1) ? 1 : 0);
            result_num >>= 1;
        }

        while (result.size() < nums_size) {
            result.push_back('0');
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};