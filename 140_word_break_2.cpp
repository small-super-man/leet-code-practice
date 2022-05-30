//
// Created by tangchao on 2022/5/28.
//

class Solution {
public:
    vector<string> _wordBreak(const string &s, const unordered_set<string> &wordSet, unordered_map<int, vector<string>> &dp_map, int pos) {
        if (pos >= s.size()) {
            return vector<sting>(1, "");
        }
        auto iter = dp_map.find(pos);
        if (iter != dp_map.end()) {
            return iter->second;
        }

        vector<string> result;
        for (int i = pos; i < s.size(); ++i) {
            string tmp_str = s.substr(pos, i - pos + 1);
            if (wordSet.count(tmp_str)) {
                vector<string> tmp_vec = _wordBreak(s, wordSet, dp_map, i + 1);
                for (auto &e : tmp_vec) {
                    string tmp_word = tmp_str;
                    if (!e.empty()) {
                        tmp_word += " ";
                    }
                    e = tmp_word + e;
                }
                result.insert(result.end(), tmp_vec.begin(), tmp_vec.end());
            }
        }

        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
       unordered_set<string> word_set(wordDict.begin(), wordDict.end());
       unordered_map<int, vector<string>> dp_map;
       return _wordBreak(s, word_set, dp_map, 0);
    }
};