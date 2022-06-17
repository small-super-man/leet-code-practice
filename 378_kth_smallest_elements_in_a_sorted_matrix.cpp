//
// Created by tangchao on 2022/6/8.
//

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row_size = matrix.size();
        int column_size = matrix[0].size();

        priority_queue<int, vector<int>, less<int>> pq;
        int count = 0;

        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                if (count < k) {
                   pq.push(matrix[i][j]);
                } else {
                    if (matrix[i][j] < pq.top()) {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }

                ++count;
            }
        }

        return pq.top();
    }
};