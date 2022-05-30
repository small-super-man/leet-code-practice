//
// Created by tangchao on 2022/5/15.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> idx;
        int start_idx =0;
        int end_idx = 0;
        int max_len = 0;
        while (end_idx  < s.size()){
            if (0 == idx.count(s[end_idx])) {
                idx[s[end_idx]] = end_idx;
                ++end_idx;
                if (end_idx - start_idx > max_len) {
                    max_len = end_idx - start_idx;
                }
            } else {
                int tmp_end = idx[s[end_idx]] + 1;
                for (int i = start_idx; i < tmp_end; ++i) {
                    idx.erase(s[i]);
                }
                start_idx = tmp_end;
                idx[s[end_idx]] = end_idx;
                ++end_idx;
            }
        }

        return max_len;
    }
};