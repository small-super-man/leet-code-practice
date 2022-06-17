//
// Created by tangchao on 2022/6/8.
//

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> first_map;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                int sum = nums1[i] + nums2[j];
                auto iter = first_map.find(sum);
                if (first_map.end() == iter) {
                    auto tmp_pair = first_map.insert({sum, 0});
                    iter = tmp_pair.first;
                }
                ++iter->second;
            }
        }

        unordered_map<int, int> second_map;
        for (int i = 0; i < nums3.size(); ++i) {
            for (int j = 0; j < nums4.size(); ++j) {
                int sum = nums3[i] + nums4[j];
                auto iter = second_map.find(sum);
                if (second_map.end() == iter) {
                    auto tmp_pair = second_map.insert({sum, 0});
                    iter = tmp_pair.first;
                }
                ++iter->second;
            }
        }

        int total_count = 0;
        for (auto &first : first_map) {
            auto second_sum = 0 - first.first;
            auto iter = second_map.find(second_sum);
            if (second_map.end() != iter) {
                total_count += (first.second * iter->second);
            }
        }

        return total_count;
    }
};

