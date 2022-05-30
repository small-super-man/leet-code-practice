//
// Created by tangchao on 2022/5/15.
//

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && ' ' == s[i]) {
            ++i;
        }

        long long result = 0;
        int sign = 1;
        if (i < s.size()) {
           if ('+' == s[i]) {
                sign = 1;
                ++i;
           } else if ('-' == s[i]) {
                sign = -1;
                ++i;
           } else if (s[i] < '0' || s[i] > '9') {
                return 0;
           }
        }

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            if (sign == 1 && result >= (1L << 31)) {
                result = (1L << 31) - 1;
                break;
            }
            if (sign == -1 && result > (1L << 31)) {
                result = (1L << 31);
                break;
            }
            ++i;
        }

        return static_cast<int>(result * sign);
    }
};

