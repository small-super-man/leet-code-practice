//
// Created by tangchao on 2022/5/30.
//

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
           return 0;
        }

        vector<bool> is_prime(n, true);
        int count = 0;
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                ++count;
                for (int j = 2; j * i < n; ++j) {
                    is_prime[j * i] = false;
                }
            }
        }
        return count;
    }
};