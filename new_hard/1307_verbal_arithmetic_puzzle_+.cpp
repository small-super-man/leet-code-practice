//
// Created by tangchao on 2022/6/29.
//

class Solution {
public:
    /*
    bool _isSolvable(const vector<vector<pair<char, int>>> &loc_alpha,
            const string &reverse,
            int rem,
            int idx,
            int subIdx,
            unordered_map<char, int> &project,
            unordered_map<int, char> &reverse_project,
            unordered_set<char> &filters) {
        if (idx >= loc_alpha.size()) {
            if (idx >= reverse.size()) {
                if (rem) {
                   return false;
                } else {
                   return 0 != project[reverse[reverse.size() - 1]];
                }
            } else {
                if (reverse.size() - 1 > idx) {
                    return false;
                }

                auto iter = project.find(reverse[idx]);
                if (iter != project.end()) {
                    return rem != 0 && iter->second == rem;
                } else {
                    return rem != 0 && 0 == reverse_project.count(rem);
                }
            }
        }

        if (idx >= reverse.size()) {
           return false;
        }

        if (subIdx >= loc_alpha[idx].size()) {
            int sum = 0;
            for (auto &e : loc_alpha[idx]) {
                sum += project[e.first] * e.second;
            }
            sum += rem;

            auto iter = project.find(reverse[idx]);
            if (iter != project.end()) {
                if (iter->second != sum % 10) {
                    return false;
                }
                return _isSolvable(loc_alpha, reverse, sum / 10, idx + 1, 0, project, reverse_project, filters);
            } else {
                int rr = sum % 10;
                if (reverse_project.count(rr)) {
                    return false;
                }
                reverse_project.insert({rr, reverse[idx]});
                project.insert({reverse[idx], rr});
                bool ret = _isSolvable(loc_alpha, reverse, sum / 10, idx + 1, 0, project, reverse_project, filters);
                reverse_project.erase(rr);
                project.erase(reverse[idx]);
                return ret;
            }
        }

        if (project.count(loc_alpha[idx][subIdx].first)) {
            return _isSolvable(loc_alpha, reverse, rem, idx, subIdx + 1, project, reverse_project, filters);
        }

        for (int i = 0; i <= 9; ++i) {
            if (filters.count(loc_alpha[idx][subIdx].first) && i == 0) {
                continue;
            }

            if (0 == reverse_project.count(i)) {
                reverse_project.insert({i, loc_alpha[idx][subIdx].first});
                project.insert({loc_alpha[idx][subIdx].first, i});

                bool ret = _isSolvable(loc_alpha, reverse, rem, idx, subIdx + 1, project, reverse_project, filters);

                reverse_project.erase(i);
                project.erase(loc_alpha[idx][subIdx].first);

                if (ret) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isSolvable(vector<string>& words, string result) {
        // loc --> [(character#1,  #count1), (character#2,  #count2)]
        vector<unordered_map<char, int>> loc_alpha_count;
        unordered_set<char> filters;
        for (auto &e : words) {
            if (e.size() > 1) {
                filters.insert(e[0]);
            }
            for (int i = e.size() - 1; i >= 0; --i) {
                int loc = e.size() - 1 - i;
                if (loc_alpha_count.size() <= loc) {
                    loc_alpha_count.push_back(unordered_map<char, int>());
                }
                auto iter = loc_alpha_count[loc].find(e[i]);
                if (iter == loc_alpha_count[loc].end()) {
                    auto tmp_pair = loc_alpha_count[loc].insert({e[i], 0});
                    iter = tmp_pair.first;
                }

                ++iter->second;
            }
        }
        vector<vector<pair<char, int>>> loc_alpha_count_vec;
        for (auto &e : loc_alpha_count) {
            vector<pair<char, int>> one_vec;
            for (auto &ee : e) {
                one_vec.push_back({ee.first, ee.second});
            }
            loc_alpha_count_vec.push_back(one_vec);
        }

        if (result.size() > 1) {
            filters.insert(result[0]);
        }
        std::reverse(result.begin(), result.end());

        unordered_map<char, int> project;
        unordered_map<int, char> reverse_project;
        return _isSolvable(loc_alpha_count_vec, result, 0, 0, 0, project, reverse_project, filters);
    }
    */
};
