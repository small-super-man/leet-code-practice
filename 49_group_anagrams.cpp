//
// Created by tangchao on 2022/5/22.
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> idx_map;
        for (int i = 0; i < strs.size(); ++i) {
            int ch[26] = {0};
            for (auto &e : strs[i]) {
                ++ch[e - 'a'];
            }

            string key = "";
            for (int j = 0; j < 26; ++j) {
                if (ch[j]) {
                    key += to_string(ch[j]) + "+" + to_string(j) + ";";
                }
            }

            auto iter = idx_map.find(key);
            if (iter == idx_map.end()) {
                auto pair = idx_map.insert({key, vector<string>()});
                iter = pair.first;
            }
            iter->second.push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto &pair : idx_map) {
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};