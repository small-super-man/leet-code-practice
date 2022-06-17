//
// Created by tangchao on 2022/6/7.
//

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l = INT_MAX;
        int m = INT_MAX;
        for (auto &e : nums) {
            if (e <= l) {
                l = e;
            } else if (e <= m) {
                m = e;
            } else {
                return true;
            }
        }

        return false;
    }

    // need proof
};