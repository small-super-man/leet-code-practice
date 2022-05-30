//
// Created by tangchao on 2022/5/24.
//

class Solution {
public:
    int numDecodings(string s) {
        if (1 == s.size()) {
            if  (s[0] == '0') {
                return  0;
            } else {
                return 1;
            }
        }

        int pre1 = 1;
        int pre2 = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            int current = 0;
            if (s[i] != '0') {
                current += pre1;

                if (i < s.size() - 1) {
                    int idx = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (idx >= 10 && idx <= 26) {
                        current += pre2;
                    }
                }
            }

            pre2 = pre1;
            pre1 = current;
        }

        return pre1;
    }
};