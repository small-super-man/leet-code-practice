//
// Created by tangchao on 2022/6/8.
//

class Solution {
public:
    int longestSubstring(string s, int k) {
        return _parseLen(s, k, 0, s.size());
    }

    int _parseLen(const string &s, int k , int start, int end) {
        unordered_map<char, int> count_map;
        for (int i = start; i < end; ++i) {
            auto ch = s[i];
            auto iter = count_map.find(ch);
            if (iter == count_map.end()) {
                auto insert_pair = count_map.insert({ch, 0});
                iter = insert_pair.first;
            }
            ++iter->second;
        }

        int max_substr_len = 0;
        int sub_start = start;
        while (sub_start < end) {
            while (sub_start < s.size() && count_map[s[sub_start]] < k) {
                ++sub_start;
            }

            if (sub_start >= s.size()) {
               break;
            }

            int sub_end = sub_start + 1;
            while (sub_end < end && count_map[s[sub_end]] >= k) {
                ++sub_end;
            }

            if (sub_start == start && sub_end == end) {
                return sub_end - sub_start;
            }

            int tmp_len = _parseLen(s, k, sub_start, sub_end);
            if (tmp_len > max_substr_len) {
                max_substr_len = tmp_len;
            }

            sub_start = sub_end;
        }

        return max_substr_len;
    }
};