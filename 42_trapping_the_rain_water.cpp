//
// Created by tangchao on 2022/5/21.
//

class Solution {
public:
    int trap(vector<int>& height) {
       int area = 0;
       // pair of (height, index)
       vector<pair<int, int>> st;

       for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[i] < st.back().first) {
                st.push_back(make_pair(height[i], i));
            } else if (height[i] > st.back().first) {
                while (height[i] > st.back().first) {
                   if (st.size() == 1) {
                        st.pop_back();
                        st.push_back(make_pair(height[i], i));
                   } else if (st[st.size() - 2].first <= height[i]) {
                        area += (i - st.back().second) * (st[st.size() - 2].first - st.back().first);
                        st.pop_back();
                   } else {
                        area += (i - st.back().second) * (height[i] - st.back().first);
                        st.back().first = height[i];
                   }
                }
            }
       }

       return area;
    }
};