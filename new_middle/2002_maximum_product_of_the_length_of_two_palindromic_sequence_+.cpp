//
// Created by tangchao on 2022/7/6.
//

class Solution {
public:
    // find the maximum possible palindromic subsequence of all the subsequence of string s
    // brute force
    int isPalindrome(const string &s, int mask) {
        int s_size = s.size();
        int i = 0;
        int j = s_size - 1;
        while (i < j) {
            while (i < j && ((1 << i) & mask) == 0) {
                ++i;
            }

            while (i < j && ((1 << j) & mask) == 0) {
                --j;
            }

            if (i < j && s[i] != s[j]) {
                return 0;
            }

            ++i;
            --j;
        }

        int bit_num = 0;
        for (int i = 0; i < s_size; ++i) {
            if ((1 << i) & mask) {
                ++bit_num;
            }
        }

        return bit_num;
    }

    int maxProduct(string s) {
        int s_size = s.size();

        unordered_map<int, int> memo;
        for (int i = 1; i < (1 << s_size); ++i) {
            int tmp = isPalindrome(s, i);
            if (tmp) {
                memo[i] = tmp;
            }
        }

        int ans = 0;
        for (auto &first : memo) {
            for (auto &second : memo) {
                if (!(first & second)) {
                    int tmp_ans = memo[first] * memo[second];
                    ans = max(tmp_ans, ans);
                }
            }
        }

        return ans;
    }
};