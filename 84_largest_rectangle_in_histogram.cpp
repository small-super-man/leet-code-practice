//
// Created by tangchao on 2022/5/24.
//

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int heights_size = heights.size();

        vector<int> h1(heights_size, 0);
        vector<int> st;
        for (int i = 0; i < heights_size; ++i) {
            if (st.empty()) {
                h1[i] = 1;
                st.push_back(i);
            } else {
                int hh = 1;
                while (!st.empty() && heights[st.back()] >= heights[i]) {
                   hh += h1[st.back()];
                   st.pop_back();
                }
                h1[i] = hh;
                st.push_back(i);
            }
        }

        vector<int> h2(heights_size, 0);
        st.clear();
        for (int i = heights_size - 1; i >= 0; --i) {
            if (st.empty()) {
                h2[i] = 1;
                st.push_back(i);
            } else {
                int hh = 1;
                while (!st.empty() && heights[st.back()] >= heights[i]) {
                    hh += h2[st.back()];
                    st.pop_back();
                }
                h2[i] = hh;
                st.push_back(i);
            }
        }

        int max_area = 0;
        for (int i = 0; i < heights_size; ++i) {
            int current_area = (h1[i] + h2[i] - 1) * heights[i];
            if (current_area > max_area) {
               max_area = current_area;
            }
        }

        return max_area;
    }
};