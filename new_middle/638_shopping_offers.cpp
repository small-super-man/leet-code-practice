//
// Created by tangchao on 2022/6/25.
//

class Solution {
public:
    /*
     *   p1, p2, p3, p4
     *   t1, t2, t3, t4
     *
     *   q11, q12, q13, q14, pp1 : z1
     *   q21, q22, q23, q24, pp2 : z2
     *   q31, q32, q33, q34, pp3 : z3
     *
     *   sum(z(i) * q(ij)) <= tj
     *   s = min(sum(pp(i) * z(i)) + sum((tj - sum(z(i)  * q(ij))) * pj))
     */

    int __shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int> &memo) {
        if (memo.count(needs))  {
            return memo[needs];
        }

        int item_num = price.size();
        int minimum = 0;
        for (int i = 0; i < item_num; ++i) {
            minimum += (price[i] * needs[i]);
        }

        for (auto &one_offer : special) {
            bool is_ok = true;
            for (int i = 0; i < item_num; ++i) {
                if (needs[i] < one_offer[i]) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) {
                for (int i = 0; i < item_num; ++i) {
                   needs[i] -= one_offer[i];
                }
                int current_fee = one_offer[item_num] + __shoppingOffers(price, special, needs, memo);
                minimum = min(current_fee, minimum);
                for (int i = 0; i < item_num; ++i) {
                    needs[i] += one_offer[i];
                }
            }
        }

        memo[needs] = minimum;
        return minimum;

    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int> memo;
        return __shoppingOffers(price, special, needs, memo);
    }
};

