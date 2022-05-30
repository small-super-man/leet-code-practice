//
// Created by tangchao on 2022/5/29.
//

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> idx_map;
        string result;

        bool is_neg = (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0);

        long long numerator_long = numerator < 0 ? -(long long)numerator : numerator;
        long long denominator_long = denominator < 0 ? -(long long)denominator : denominator;

        long long remain = numerator_long;
        result = to_string(remain / denominator_long);
        remain = remain % denominator_long;
        if (remain) {
            result.push_back('.');
            idx_map.insert({remain, result.size()});
        }
        while (remain) {
            do {
               remain *= 10;
               if (remain >= denominator_long) {
                  break;
               }
               result.push_back('0');
            } while (true);

            result += to_string(remain / denominator_long);
            remain = remain % denominator_long;

            if (!remain) {
                break;
            }

            auto iter = idx_map.find(remain);
            if (iter != idx_map.end()) {
                result.insert(result.begin() + iter->second, '(');
                result.push_back(')');
                break;
            } else {
                idx_map.insert({remain, result.size()});
            }
        }

        if (is_neg && result != "0") {
            result = "-" + result;
        }

        return result;
    }
};