//
// Created by tangchao on 2022/7/6.
//

class Solution {
public:
    void permutation(string &candidate, int pos, int maxLen, vector<string> &candidates) {
        if (pos == maxLen) {
            candidates.emplace_back(candidate.begin(), candidate.begin() + maxLen);
            return;
        }

        unordered_set<char> visited;
        for (int i = pos; i < candidate.size(); ++i) {
            if (visited.count(candidate[i])) {
                continue;
            }
            visited.insert(candidate[i]);
            swap(candidate[pos], candidate[i]);
            permutation(candidate, pos + 1, maxLen, candidates);
            swap(candidate[pos], candidate[i]);
        }

        if (pos == 0 && maxLen > 1) {
            permutation(candidate, pos, maxLen - 1, candidates);
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int count[26] = {0};
        for (auto &e : s) {
            ++count[e - 'a'];
        }

        string candidate;
        for (int i = 25; i >= 0; --i) {
            while (count[i] >= k) {
                candidate.push_back('a' + i);
                count[i] -= k;
            }
        }

        if (candidate.empty()) {
            return "";
        }

        int s_size = s.size();

        vector<string> result_candidates;
        permutation(candidate, 0, min(s_size / k, candidate.size()), result_candidates);

        for (auto &e : result_candidates) {
            // check if 'e' repeat k times in s;
            for (int ee = 0, i = 0, cc = 0; i < s_size; ++i) {
                if (s[i] == e[ee]) {
                    ++ee;
                    if (ee >= e.size()) {
                        ++cc;
                        if (cc >= k) {
                            return e;
                        }
                        ee = 0;
                    }
                }
            }
        }

        assert(false);
        return "";
    }
};