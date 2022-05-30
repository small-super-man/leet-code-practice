//
// Created by tangchao on 2022/5/23.
//

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result(1, vector<int>());
       for (auto &e : nums) {
           vector<vector<int>> tmp;
           for (auto &v : result) {
               tmp.push_back(v);
               v.push_back(e);
               tmp.push_back(v);
           }
           tmp.swap(result);
       }

       return result;
    }
};