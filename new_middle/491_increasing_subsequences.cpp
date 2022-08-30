//
// Created by tangchao on 2022/6/24.
//

class Solution {
public:
    /*
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> filer_result;
        int nums_size = nums.size();
        vector<vector<vector<int>>> mid_result(nums_size, vector<vector<int>>());

        for (int i = nums_size - 1; i >= 0; --i) {
            vector<vector<int>> tmp;
            tmp.push_back(vector<int>(1, nums[i]));
            for (int j = i + 1; j < nums_size; ++j) {
                if (nums[i] <= nums[j]) {
                    for (auto &vec : mid_result[j]) {
                        vector<int> sub_vec = vec;
                        sub_vec.insert(sub_vec.begin(), nums[i]);
                        auto pp = filer_result.insert(sub_vec);
                        if (pp.second) {
                            tmp.push_back(sub_vec);
                        }
                    }
                }
            }
            mid_result[i] = tmp;
        }

        return vector<vector<int>>(filer_result.begin(), filer_result.end());
    }
    */
    /*
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<int> filtered_result;
        unordered_map<int, vector<int>> idx_map;

        int nums_size = nums.size();
        for (int i = nums_size - 1; i >= 0; --i) {
            vector<int> tmp;
            tmp.push_back(1 << i);
            for (int j = i + 1; j < nums_size; ++j) {
                if (nums[i] <= nums[j]) {
                    for (auto &one_mask : idx_map[j]) {
                        int tmp_mask = one_mask;
                        tmp_mask |= (1 << i);
                        filtered_result.insert(tmp_mask);
                        tmp.push_back(tmp_mask);
                    }
                }
            }
            idx_map[i] = tmp;
        }

        set<vector<int>> result;
        for (auto &e : filtered_result) {
            vector<int> tmp;
            for (int i = 0; i < 15; ++i) {
                if (e & (1 << i)) {
                    tmp.push_back(nums[i]);
                }
            }
            result.insert(tmp);
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
    */

    /*
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        int nums_size = nums.size();

        for (int i = nums_size - 1; i >= 0; --i) {
            set<vector<int>> tmp_set = result;
            for (auto &e : result) {
                if (nums[i] <= e[0]) {
                    vector<int> tmp_vec = e;
                    tmp_vec.insert(tmp_vec.begin(), nums[i]);
                    tmp_set.insert(tmp_vec);
                }
            }
            result.swap(tmp_set);

            for (int j = i + 1; j < nums_size; ++j) {
               if (nums[i] <= nums[j]) {
                   vector<int> tmp;
                   tmp.push_back(nums[i]);
                   tmp.push_back(nums[j]);
                   result.insert(tmp);
               }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
     */

    // 1<= nums.size() <= 15; - 100 <= nums[i] <= 100;
    vector<vector<int>> findSubsequences(vector<int>& nums) {

    }

};
