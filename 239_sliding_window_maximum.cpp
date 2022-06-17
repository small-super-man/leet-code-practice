//
// Created by tangchao on 2022/6/3.
//

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<pair<int, int>> dq;
        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && dq.back().second <= i - k) {
                dq.pop_back();
            }
            while (!dq.empty() && dq.front().first <= nums[i]) {
                dq.pop_front();
            }
            dq.push_front(make_pair(nums[i], i));
            if (i >= k - 1) {
                result.push_back(dq.back().first);
            }
        }

        return result;
    }
};