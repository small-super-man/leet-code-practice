//
// Created by tangchao on 2022/5/21.
//

class Solution {
public:
    int divide(int dividend, int divisor) {
       long long div1 = dividend;
       long long div2 = divisor;
       int sign = 1;
       if (div1 < 0 && div2 > 0 || div1 > 0 && div2 < 0) {
            sign = -1;
       }
       if (div1 < 0) {
            div1 = -div1;
       }
       if (div2 < 0) {
            div2 = -div2;
       }

       long long total_multiple = 0;
       while (div1 >= div2) {
            long long tmp_multiple = 1;
            long long tmp_div2 = div2;
            while (tmp_div2 + tmp_div2 < div1) {
                tmp_multiple += tmp_multiple;
                tmp_div2 += tmp_div2;
            }
            div1 -= tmp_div2;
            total_multiple += tmp_multiple;
       }

       if (sign == -1) {
           total_multiple = -total_multiple;
       }

       if (total_multiple > INT_MAX) {
           total_multiple = INT_MAX;
       }
       if (total_multiple < INT_MIN) {
           total_multiple = INT_MIN;
       }

       return static_cast<int>(total_multiple);
    }
};