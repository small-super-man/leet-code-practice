//
// Created by tangchao on 2022/5/18.
//

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        vector<string> memo = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> st(digits.size(), 0);

        int i = 0;
        int j = 0;
        do {
            st[i] = j;
            ++i;
            j = 0;

            if (i >= digits.size()) {
                string tmp_result = "";
                for (int k = 0; k < digits.size(); ++k) {
                    tmp_result.push_back(memo[digits[k] - '2'][st[k]]);
                }
                result.push_back(tmp_result);

                i = digits.size() - 1;
                while (i >= 0 && st[i] >= memo[digits[i] - '2'].size() - 1) {
                    --i;
                }

                if (i >= 0) {
                    j = st[i] + 1;
                }
            }
        } while(i >= 0);

        return result;
    }
};

