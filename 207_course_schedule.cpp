//
// Created by tangchao on 2022/5/30.
//

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in_degree(numCourses, 0);
        queue<int> qt;
        for (auto &e : prerequisites) {
            graph[e[1]].push_back(e[0]);
            ++in_degree[e[0]];
        }
        for (int i = 0; i < numCourses; ++i) {
           if (!in_degree[i]) {
              qt.push(i);
           }
        }

        while (!qt.empty()) {
            auto front = qt.front();
            qt.pop();
            for (auto &e : graph[front]) {
                if (--in_degree[e] == 0) {
                    qt.push(e);
                }
            }
        }

        for (auto &e : in_degree) {
            if (e) {
               return false;
            }
        }

        return true;
    }
};

