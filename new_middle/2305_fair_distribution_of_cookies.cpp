//
// Created by tangchao on 2022/6/29.
//

class Solution {
public:
    int _distribute(const vector<int> &cookies, int idx, int k, vector<int> &bags) {
        if (idx >= cookies.size()) {
            int max_num = 0;
            for (auto &e : bags) {
                if (max_num < e) {
                    max_num = e;
                }
            }
            return max_num;
        }

        int max_num = INT_MAX;
        for (int i = 0; i < k; ++i) {
            bags[i] += cookies[idx];
            int sub_num = _distribute(cookies, idx + 1, k, bags);
            bags[i] -= cookies[idx];
            if (sub_num < max_num) {
               max_num = sub_num;
            }
        }

        return max_num;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> bags(k, 0);
        return _distribute(cookies, 0, k, bags);
    }
};