//
// Created by tangchao on 2022/6/26.
//

class Solution {
public:
    /*
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<string> result;
        for (int i = 1; i <= 9; ++i) {
            if (i + k < 10 || i >= k) {
                result.push_back(std::to_string(i));
            }
        }

        for (int i = 1; i < n; ++i) {
            int current_result_size =
            for (int j = 0; j < current_result_size; ++j) {
                auto e = result[j];
                int tmp = e[e.size() - 1] - '0';
                if (tmp >= k && tmp + k < 10) {
                    if (k) {
                        e.push_back('0' + tmp - k);
                        result.push_back(e);
                        result[j].push_back('0' + tmp + k);
                    } else {
                        result[j].push_back('0' + tmp - k);
                    }
                } else if (tmp >= k) {
                    result[j].push_back('0' + tmp - k);
                } else if (tmp + k < 10) {
                    result[j].push_back('0' + tmp + k);
                }
            }
        }

        vector<int> res;
        res.reserve(result.size());
        for (auto &e : result) {
            res.push_back(stoi(e));
        }

        return res;
    }
    */


};