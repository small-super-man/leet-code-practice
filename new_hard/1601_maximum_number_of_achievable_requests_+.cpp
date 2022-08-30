//
// Created by tangchao on 2022/7/1.
//

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
       int m = requests.size();
       int result = 0;
       for (int i = 1; i < (1 << m); ++i) {
            vector<int> balance(n, 0);
            int one_num = 0;
            for (int j = 0; j < m; ++j) {
                if (i & (1 << j)) {
                    --balance[requests[j][0]];
                    ++balance[requests[j][1]];
                    ++one_num;
                }
            }
            if (one_num <= result) {
                continue;
            }

            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (balance[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                result = one_num;
            }
       }

       return result;
    }
};