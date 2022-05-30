//
// Created by tangchao on 2022/5/19.
//

class Solution {
public:
    // dynamic programming
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> memo;
        memo.push_back(vector<string>(1, ""));
        for (int i = 1; i <= n; ++i) {
            vector<string> tmp_result;
            for (int j = 0; j <= i - 1; ++j) {
                for  (auto iter = memo[j].begin(); iter != memo[j].end(); ++iter) {
                    int sub_idx = i - 1 - j;
                    for (auto sub_iter = memo[sub_idx].begin(); sub_iter != memo[sub_idx].end(); ++sub_iter) {
                        tmp_result.push_back(std::move("(" + *iter + ")" + *sub_iter));
                    }
                }
            }
            memo.push_back(tmp_result);
        }
        return memo[n];
    }
};