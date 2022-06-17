//
// Created by tangchao on 2022/6/7.
//

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> count_map;
       for (auto &e : nums) {
            auto iter = count_map.find(e);
            if (iter == count_map.end()) {
               auto insert_pair = count_map.insert({e, 0});
               iter = insert_pair.first;
            }
            ++iter->second;
       }
       auto cmp = [](const pair<int, int> &one, const pair<int, int> &two){
            return one.second < two.second;
       };
       priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> qt(cmp);
       for (auto &one_pair : count_map) {
            qt.push(one_pair);
       }

       vector<int> most_k_vec;
       while (k > 0) {
            most_k_vec.push_back(qt.top().first);
            qt.pop();
            --k;
       }

       return most_k_vec;
    }
};