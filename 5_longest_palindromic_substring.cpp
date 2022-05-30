//
// Created by tangchao on 2022/5/15.
//

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
           return s;
        }

        int even_start = -1;
        int max_even_half_len = 0;
        for (int i = 0; i < s.size() && (s.size() - i - 1)  >  max_even_half_len; i++) {
            int j = i;
            int k = i + 1;
            while (j >= 0  &&  k < s.size()  && s[j] == s[k]) {
                --j;
                ++k;
            }

            if (i - j >= max_even_half_len) {
                max_even_half_len = i - j;
                even_start = j + 1;
            }
        }

        int odd_start = -1;
        int max_odd_half_len = 0;
        for (int i = 0; i < s.size() && (s.size() - i - 1) > max_odd_half_len; i++) {
            int j = i - 1;
            int k = i + 1;
            while (j >= 0 && k < s.size() && s[j] == s[k]) {
               --j;
               ++k;
            }

            if (i - j - 1 >= max_odd_half_len) {
                max_odd_half_len = i - j - 1;
                odd_start = j + 1;
            }
        }

        if (max_odd_half_len >= max_even_half_len) {
            return  s.substr(odd_start, (max_odd_half_len << 1) + 1);
        } else {
            return  s.substr(even_start, max_even_half_len << 1);
        }
    }
};