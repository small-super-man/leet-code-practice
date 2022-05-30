//
// Created by tangchao on 2022/5/30.
//

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in_degree(numCourses, 0);
        for (auto &sub_vec : prerequisites) {
            graph[sub_vec[1]].push_back(sub_vec[0]);
            ++in_degree[sub_vec[0]];
        }
        queue<int> zero_degree_queue;
        for (int i = 0; i < numCourses; ++i) {
            if (0 == in_degree[i]) {
                zero_degree_queue.push(i);
            }
        }

        vector<int> class_seq;
        while (!zero_degree_queue.empty()) {
            auto front = zero_degree_queue.front();
            class_seq.push_back(front);
            zero_degree_queue.pop();

            for (auto &neighbor : graph[front]) {
                if (0 == --in_degree[neighbor]) {
                    zero_degree_queue.push(neighbor);
                }
            }
        }

        // just can use class_seq.size() != numCourses
        for (auto &one_degree : in_degree) {
            if (one_degree) {
               return vector<int>();
            }
        }

        return class_seq;
    }
};