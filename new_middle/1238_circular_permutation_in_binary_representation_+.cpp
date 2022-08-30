//
// Created by tangchao on 2022/6/28.
//

class Solution {
public:
    bool oneBitDiff(int n, int x, int y) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
           if ((x & (1 << i)) != (y & (1 << i))) {
               ++count;
           }
        }
        return count == 1;
    }

    bool dfs(int n, int x, unordered_set<int> &visited, vector<int> &currentPath, vector<int> &path) {
        visited.insert(x);
        currentPath.push_back(x);

        if (currentPath.size() == (1 << n) && oneBitDiff(n, x, currentPath[0])) {
            path = currentPath;
            return true;
        }

        for (int i = 0; i < n; ++i) {
            int xx = x ^ (1 << i);
            if (0 == visited.count(xx)) {
                bool ret = dfs(n, xx, visited, currentPath, path);
                if (ret) {
                   return true;
                }
            }
        }

        visited.erase(x);
        currentPath.pop_back();
        return false;
    }

    vector<int> circularPermutation(int n, int start) {
       vector<int> path;
       vector<int> current_path;
       unordered_set<int> visited;

       int ret = dfs(n, start, visited, current_path, path);
       assert(ret);

       return path;
    }
};

