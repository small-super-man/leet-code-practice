//
// Created by tangchao on 2022/7/3.
//

class Solution {
public:
    /* do backtracking according to every number from 2 to n, but it need compare all possible feasible solutions, and which result in timeout exceeded...
    void _construct(int idx, vector<int> &result, vector<int> &finalResult) {
        if (idx < 2) {
            bool flag = false;
            for (auto i = 0; i < result.size(); ++i) {
                if (result[i] != finalResult[i]) {
                    flag = result[i] > finalResult[i];
                    break;
                }
            }
            if (flag) {
                finalResult = result;
            }

            return;
        }

        for (int i = 0, limit = result.size() - 1 - idx; i <= limit; ++i) {
            if (0 == result[i] && 0 == result[i + idx]) {
                result[i] = idx;
                result[i + idx] = idx;
                _construct(idx - 1, result, finalResult);
                result[i] = 0;
                result[i + idx] = 0;
            }
        }
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result((n << 1) - 1, 0);
        vector<int> tmp((n << 1) - 1, 0);
        _construct(n, tmp, result);

        for (auto &e : result) {
            if (!e) {
                e = 1;
            }
        }

        return result;
    }
     */

    bool _construct(int pos, int n, vector<int> &result, unordered_set<int> &usedSet) {
        if (usedSet.size() == n) {
            return true;
        }
        while (pos < result.size() && result[pos]) {
            ++pos;
        }
        if (pos >= result.size()) {
           return false;
        }

        for (int i = n; i >= 1; --i) {
            if (i > 1) {
                if (0 == usedSet.count(i) && pos + i < result.size() && 0 == result[pos + i]) {
                    result[pos] = i;
                    result[pos + i] = i;
                    usedSet.insert(i);
                    bool ret = _construct(pos + 1, n, result, usedSet);
                    if (ret) {
                        return true;
                    }
                    result[pos] = 0;
                    result[pos + i] = 0;
                    usedSet.erase(i);
                }
            } else {
               if (0 == usedSet.count(i)) {
                   result[pos] = i;
                   usedSet.insert(i);
                   bool ret = _construct(pos + 1, n, result, usedSet);
                   if (ret) {
                       return true;
                   }
                   result[pos] = 0;
                   usedSet.erase(i);
               }
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
       vector<int> result((n << 1) - 1, 0);
       unordered_set<int> used_set;
       bool ret = _construct(0, n, result, used_set);
       assert(ret);
       return result;
    }
};