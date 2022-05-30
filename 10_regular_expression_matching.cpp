//
// Created by tangchao on 2022/5/16.
//

class Solution {
public:
    bool _isXing(const string &p, int p_start) {
        if ((p.size() - p_start) & 1) {
            return false;
        }
        for (int i = p_start + 1; i < p.size(); i += 2) {
            if (p[i] != '*') {
                return false;
            }
        }
        return true;
    }
    bool _isMatch(const string &s, int s_start, const string &p, int p_start) {
        if (s_start >= s.size()) {
            return p_start >= p.size() || _isXing(p, p_start);
        }

        int i = s_start;
        int j = p_start;
        while (i < s.size() && j < p.size()) {
            if (p[j] == '.' && j + 1 >= p.size()) {
                ++i;
                ++j;
                continue;
            }

            if (p[j] == '.' && j + 1 < p.size() && p[j + 1] != '*') {
                ++i;
                ++j;
                continue;
            }

            if (p[j] == '.' && j + 1 < p.size() && p[j + 1] == '*') {
                int tmp_j = j + 2;
                for (int tmp_i = i; tmp_i <= s.size(); ++tmp_i) {
                    if (_isMatch(s, tmp_i, p, tmp_j)) {
                        return true;
                    }
                }
                return false;
            }

            if (j + 1 < p.size() && p[j + 1] == '*') {
                if (s[i] != p[j]) {
                    return _isMatch(s, i, p, j + 2);
                }

                int tmp_j = j + 2;

                for (int tmp_i = i; tmp_i <= s.size() && (tmp_i == i || s[tmp_i - 1] == s[i]); ++tmp_i) {
                    if (_isMatch(s, tmp_i, p, tmp_j)) {
                        return true;
                    }
                }

                return false;
            }

            if (s[i] != p[j]) {
                return false;
            }

            ++i;
            ++j;
        }

        return i >= s.size() && (j >= p.size() || _isXing(p, j));
    }

    bool isMatch(string s, string p) {
        return _isMatch(s, 0, p, 0);
    }
};