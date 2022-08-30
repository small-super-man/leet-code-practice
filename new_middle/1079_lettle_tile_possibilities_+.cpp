//
// Created by tangchao on 2022/6/27.
//

class Solution {
public:
    /*
    unordered_set<string> constructStr(const string &str, int len) {
        if (len <= 0) {
            return unordered_set<string>({""});
        }

        unordered_set<string> result;
        for (int i = 0; i < str.size(); ++i) {
            char ch = str[i];
            string tmp = str;
            tmp.erase(tmp.begin() + i);
            unordered_set<string> tmp_res = constructStr(tmp, len - 1);
            for (auto &e : tmp_res) {
                string ee;
                ee.push_back(ch);
                result.insert(ee + e);
            }
        }

        return result;
    }

    int numTilePossibilities(string tiles) {
        int size = tiles.size();
        unordered_set<string> result;
        for (int len = 1; len <= size; ++len) {
            unordered_set<string> tmp_set = constructStr(tiles, len);
            result.insert(tmp_set.begin(), tmp_set.end());
        }

        return result.size();
    }
    */

    int numTilePossibilities(string tiles) {

    }

};

