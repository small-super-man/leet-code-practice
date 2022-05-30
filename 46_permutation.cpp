//
// Created by tangchao on 2022/5/22.
//

class Solution {
public:
    /*
     * use recursion
     *
    vector<vector<int>> _permute(vector<int> &nums, int start_pos) {
        if (start_pos >= nums.size() - 1) {
            return vector<vector<int>>(1, vector<int>(1, nums[nums.size() - 1]));
        }

        vector<vector<int>> result;
        for (int i = start_pos; i < nums.size(); ++i) {
            swap(nums[start_pos], nums[i]);

            vector<vector<int>> tmp_vec = _permute(nums, start_pos + 1);
            for (auto iter = tmp_vec.begin(); iter != tmp_vec.end(); ++iter) {
                vector<int> tt(1, nums[start_pos]);
                tt.insert(tt.end(), iter->begin(), iter->end());
                result.push_back(std::move(tt));
            }

            swap(nums[start_pos], nums[i]);
        }

        return result;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        return _permute(nums, 0);
    }
    */

    /*
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        int nums_size = nums.size();
        vector<int> st(1, 0);
        set<int> candidate;
        for (int i = 1; i < nums_size; ++i) {
            candidate.insert(i);
        }
        do {
            if (st.size() < nums_size) {
                st.push_back(*candidate.begin());
                candidate.erase(candidate.begin());
            }

            if (st.size() >= nums_size) {
                vector<int> tmp_res;
                for (int i = 0; i < nums_size; ++i) {
                    tmp_res.push_back(nums[st[i]]);
                }
                result.push_back(tmp_res);

                while (!st.empty() && candidate.upper_bound(st.back()) == candidate.end()) {
                    int back = st.back();
                    st.pop_back();
                    candidate.insert(back);
                }

                if (!st.empty()) {
                    auto iter = candidate.upper_bound(st.back());
                    int back = st.back();
                    st.pop_back();
                    st.push_back(*iter);
                    candidate.erase(iter);
                    candidate.insert(back);
                }
            }
        } while (!st.empty());

        return result;
    }
    */
};

