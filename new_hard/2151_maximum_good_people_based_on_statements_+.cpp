//
// Created by tangchao on 2022/7/11.
//

class Solution {
public:
    bool _check(int mask, const vector<vector<int>>& statements) {
        int person_num = statements.size();
        for (int i = 0; i < person_num; ++i) {
            bool good_person = mask & (1 << i);
            for (int j = 0; j < person_num; ++j) {
                bool sub_good_person = mask & (1 << j);
                if (statements[i][j] == 2) {
                    continue;
                }
                if (good_person) {
                    if (sub_good_person && !statements[i][j] || !sub_good_person && statements[i][j]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int person_num = statements.size();
        int max_good = 0;
        for (int i = 0; i < (1 << person_num); ++i) {
           bool ret = _check(i, statements);
           if (ret) {
                max_good = max(max_good, __builtin_popcount(i));
           }
        }

        return max_good;
    }
};