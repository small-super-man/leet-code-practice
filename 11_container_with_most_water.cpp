//
// Created by tangchao on 2022/5/16.
//

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int max_area = 0;
        while (i < j) {
            if (height[i] <= height[j]) {
                int min_h = min(height[i], height[j]);
                int tmp_area = min_h * (j - i);
                if (tmp_area > max_area) {
                    max_area = tmp_area;
                }
                ++i;
            } else {
                int min_h = min(height[i], height[j]);
                int tmp_area = min_h * (j - i);
                if (tmp_area > max_area) {
                    max_area = tmp_area;
                }
                --j;
            }
        }

        return max_area;
    }
};

