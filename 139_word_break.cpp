//
// Created by tangchao on 2022/5/28.
//

class Solution {
public:
    bool _wordBreak(const string s, const unordered_set<string> &wordSet, unordered_map<int, bool> &res_memo, int pos) {
        if (pos >= s.size()) {
           return true;
        }

        auto iter = res_memo.find(pos);
        if (iter != res_memo.end()) {
           return iter->second;
        }

        bool result = false;
        for (int i = pos; i < s.size(); ++i) {
            string prefix = s.substr(pos, i - pos + 1);
            if (wordSet.count(prefix) && _wordBreak(s, wordSet, res_memo, i + 1)) {
                result = true;
            }
        }

        res_memo.insert({pos, result});

        return result;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> res_memo;
        return _wordBreak(s, word_set, res_memo, 0);
    }
};