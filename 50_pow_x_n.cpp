//
// Created by tangchao on 2022/5/22.
//

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
           return 1;
        }

        int sign = 1;
        long long nn = n;
        if (nn < 0) {
            sign = -1;
            nn = -nn;
        }

        double result = 1;
        double y = x;
        int shift = 0;
        while (shift <= 31) {
            if ((1L << shift) & nn) {
                result *= y;
            }
            ++shift;
            y *= y;
        }

        if (sign == -1) {
            result = 1.0 / result;
        }

        return result;
    }
};