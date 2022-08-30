//
// Created by tangchao on 2022/7/1.
//

class Solution {
public:
    int _maxUniqueSplit(const string &s, int idx, unordered_set<string> &filter) {
        int max_split = 0;
        for (int end_idx = idx; end_idx < s.size(); ++end_idx) {
            string current_str = s.substr(idx, end_idx - idx + 1);
            if (filter.count(current_str)) {
                continue;
            }

            filter.insert(current_str);
            int sub_num = _maxUniqueSplit(s, end_idx + 1, filter);
            if (max_split < sub_num + 1) {
                max_split = sub_num + 1;
            }
            filter.erase(current_str);
        }

        return max_split;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> filter;
        return _maxUniqueSplit(s, 0, filter);
    }
};

