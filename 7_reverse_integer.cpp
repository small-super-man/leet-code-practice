//
// Created by tangchao on 2022/5/15.
//

class Solution {
public:
    int reverse(int x) {
       if (x == 0) {
          return 0;
       }

       long long xx = x;
       int sign = 1;
       if (xx < 0) {
          sign = -1;
          xx = -xx;
       }

       long long result = 0;
       while (xx) {
          result = result * 10 + (xx % 10);
          xx /= 10;
       }

       if (sign == 1 && result >= (1L << 31)) {
           return 0;
       }

       if (sign == -1 && result > (1L << 31)) {
            return 0;
       }

       return static_cast<int>(result * sign);
    }
};

