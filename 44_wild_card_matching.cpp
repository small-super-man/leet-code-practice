//
// Created by tangchao on 2022/5/21.
//

class Solution {
public:
    bool _isAllXing(const string &p, int p_start) {
        for (int i = p_start; i < p.size(); ++i) {
            if ('*' != p[i]) {
                return false;
            }
        }

        return true;
    }

    bool _isMatch(const string &s, const string &p, int s_start, int p_start) {
        if (s_start >= s.size()) {
            return p_start >= p.size() || _isAllXing(p, p_start);
        }

        int s_idx = s_start;
        int p_idx = p_start;
        while (s_idx < s.size() && p_idx < p.size()) {
            if ('?' == p[p_idx]) {
                ++s_idx;
                ++p_idx;
                continue;
            }

            if ('*' == p[p_idx]) {
                while(p_idx < p.size() && '*' == p[p_idx]) {
                    ++p_idx;
                }
                for (int i = s_idx; i <= s.size(); ++i) {
                    if (_isMatch(s, p, i, p_idx)) {
                        return true;
                    }
                }
                return false;
            }

            if (p[p_idx] != s[s_idx]) {
                return false;
            }

            ++s_idx;
            ++p_idx;
        }

        return s_idx >= s.size() && (p_idx >= p.size() || _isAllXing(p, p_idx));
    }

    bool isMatch(string s, string p) {
        return _isMatch(s, p, 0, 0);
    }
};