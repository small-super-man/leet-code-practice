//
// Created by tangchao on 2022/6/28.
//

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> arr_bits;
        for (auto &e : arr) {
            int one_bits = 0;
            bool flag = true;
            for (auto &v : e) {
                if (one_bits & (1 << (v - 'a'))) {
                    flag = false;
                    break;
                }
                one_bits |= (1 << (v - 'a'));
            }
            if (flag) {
                arr_bits.push_back(one_bits);
            }
        }

        vector<unordered_set<int>> bits_map;
        for (int i = 0; i < arr_bits.size(); ++i) {
            unordered_set<int> bit_set;
            int current = arr_bits[i];
            bit_set.insert(current);
            for (int j = i - 1; j >= 0; --j) {
                if (0 == (current & arr_bits[j])) {
                    for (auto &e : bits_map[j]) {
                        if (0 == (e & current)) {
                            bit_set.insert(e | current);
                        }
                    }
                }
            }
            bits_map.push_back(bit_set);
        }

        int  max_len  = 0;
        for (auto &e : bits_map) {
            for (auto &ee : e)  {
                int len = 0;
                for (int i = 0; i < 26; ++i) {
                    if (ee & (1 << i)) {
                        ++len;
                    }
                }
                if (max_len < len) {
                   max_len = len;
                }
            }
        }

        return max_len;
    }
};