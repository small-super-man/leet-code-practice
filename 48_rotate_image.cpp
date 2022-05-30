//
// Created by tangchao on 2022/5/22.
//

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrix_size = matrix.size();
        int total_level = matrix_size / 2;
        for (int i = 0; i < total_level; ++i) {
            int num = matrix_size - i * 2 - 1;

            vector<int> tmp(num, 0);
            for (int j = matrix_size - 1 - i; j > i; --j) {
                tmp[matrix_size - 1 - i - j] = matrix[j][i];
            }

            for (int j = 0; j < num; ++j) {
                matrix[matrix_size - 1 - i - j][i] = matrix[matrix_size - 1 - i][matrix_size - 1 - i - j];
                matrix[matrix_size - 1 - i][matrix_size - 1 - i - j] = matrix[i + j][matrix_size - 1 - i];
                matrix[i + j][matrix_size - 1 - i] = matrix[i][i + j];
                matrix[i][i + j] = tmp[j];
            }
        }
    }
};