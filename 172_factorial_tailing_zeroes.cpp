//
// Created by tangchao on 2022/5/30.
//

class Solution {
public:
    int trailingZeroes(int n) {
       int num_two = 0;
       int num_five = 0;
       for (int i = 1; i <= n; ++i) {
           int nn = i;
           while (nn && (nn & 1) == 0) {
              ++num_two;
              nn = nn >> 1;
           }
           while (nn && nn % 5 == 0) {
              ++num_five;
              nn /= 5;
           }
       }

        return min(num_two, num_five);
    }
};