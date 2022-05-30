//
// Created by tangchao on 2022/5/23.
//

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &one, const vector<int> &two){
            return one[0] < two[0] || one[0] == two[0] && one[1] < two[1];
        });

        vector<vector<int>> result;
        int intervals_size = intervals.size();
        int i = 0;
        while (i < intervals_size) {
            vector<int> tmp_vec;
            tmp_vec.push_back(intervals[i][0]);
            int left = intervals[i][1];
            int j = i + 1;
            while (j < intervals_size && left >= intervals[j][0]) {
                if (left < intervals[j][1]) {
                    left = intervals[j][1];
                }
                ++j;
            }
            tmp_vec.push_back(left);
            result.push_back(std::move(tmp_vec));
            i = j;
        }

        return result;
    }
};