//
// Created by tangchao on 2022/6/26.
//

class Solution {
public:
    /*
    vector<string> letterCasePermutation(string s) {
        int s_size = s.size();
        set<string> result;
        result.insert("");
        for (int i = s_size - 1; i >= 0; --i) {
            set<string> tmp;
            char ch = s[i];
            if (std::isalpha(ch)) {
                ch = std::tolower(ch);
                for (auto &e : result) {
                    string ss(1, ch);
                    tmp.insert(ss + e);
                }

                ch = std::toupper(ch);
                for (auto &e : result) {
                    string ss(1, ch);
                    tmp.insert(ss + e);
                }
            } else {
                for (auto &e : result) {
                    string ss(1, ch);
                    tmp.insert(ss + e);
                }
            }

            swap(tmp, result);
        }

        return vector<string>(result.begin(), result.end());
    }
    */

    vector<string> letterCasePermutation(string s) {
        vector<string> result(1, "");
        int s_size = s.size();
        for (int i = 0; i < s_size; ++i) {
            if (std::isalpha(s[i])) {
                int tmp_result_size = result.size();
                for (int j = 0; j < tmp_result_size; ++j) {
                    string tmp_str = result[j];
                    tmp_str.push_back(std::toupper(s[i]));
                    result.push_back(tmp_str);
                    result[j].push_back(std::tolower(s[i]));
                }
            } else {
                int tmp_result_size = result.size();
                for (int j = 0; j < tmp_result_size; ++j) {
                    result[j].push_back(std::tolower(s[i]));
                }
            }
        }

        return result;
    }
};