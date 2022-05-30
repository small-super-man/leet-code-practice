//
// Created by tangchao on 2022/5/26.
//

class Solution {
public:
    bool _isParlindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }

        return start >= end;
    }

    vector<vector<string>> partition(string s) {
        int s_size = s.size();
        vector<vector<vector<string>>> dp(s_size + 1, vector<vector<string>>());
        dp[s_size] = vector<vector<string>>(1, vector<string>());
        for (int i = s_size - 1; i >= 0; --i) {
            for (int j = i; j < s_size; ++j)  {
                if (_isParlindrome(s, i, j))  {
                    for (auto &e : dp[j + 1]) {
                        vector<string> tmp = e;
                        tmp.insert(tmp.begin(), s.substr(i, j - i + 1));
                        dp[i].push_back(tmp);
                    }
                }
            }
        }
        return dp[0];
    }
};