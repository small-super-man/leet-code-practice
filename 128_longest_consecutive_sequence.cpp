//
// Created by tangchao on 2022/5/26.
//

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int nums_size = nums.size();

        unordered_map<int, unordered_set<int>> union_id_to_values;
        unordered_map<int, int> value_to_union_idx;
        int current_union_idx = 0;
        for (auto &e : nums) {
            if (value_to_union_idx.count(e)) {
                continue;
            }

            int tmp_idx = -1;

            int former = e - 1;
            auto former_iter = value_to_union_idx.find(former);
            if (former_iter != value_to_union_idx.end()) {
                tmp_idx = former_iter->second;
                union_id_to_values[tmp_idx].insert(e);
            }

            int after = e + 1;
            auto iter = value_to_union_idx.find(after);
            if (iter != value_to_union_idx.end()) {
               if (-1 == tmp_idx) {
                   tmp_idx = iter->second;
                   union_id_to_values[tmp_idx].insert(e);
               } else {
                   assert(former_iter != value_to_union_idx.end());
                   int former_idx = former_iter->seoncd;
                   int after_idx = iter->second;
                   if (union_id_to_values[former_idx].size() < union_id_to_values[after_idx].size()) {
                        swap(former_idx, after_idx);
                   }
                   tmp_idx = former_idx;

                   //merge after_idx to former_idx
                   for (auto &ee : union_id_to_values[after_idx]) {
                        value_to_union_idx[ee] = former_idx;
                   }
                   union_id_to_values[former_idx].insert(union_id_to_values[after_idx].begin(), union_id_to_values[after_idx].end());
                   union_id_to_values.erase(after_idx);
               }
            }

            if (-1 == tmp_idx) {
                tmp_idx = current_union_idx++;
                union_id_to_values.insert({tmp_idx, unordered_set<int>({e})});
            }

            value_to_union_idx.insert({e, tmp_idx});
        }

        int result = 0;
        for (auto &map_pair : union_id_to_values) {
            if (result < map_pair.second.size()) {
                result = map_pair.second.size();
            }
        }

        return result;
    }
};
