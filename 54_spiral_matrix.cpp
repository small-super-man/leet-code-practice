//
// Created by tangchao on 2022/5/22.
//

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        vector<int> result;
        int i = 0;
        int j = 0;
        int loop_count = 0;
        while (true) {
            if (j >= column_size - loop_count) {
               break;
            }
            while (j < column_size - loop_count) {
                result.push_back(matrix[i][j]);
                ++j;
            }
            --j;

            ++i;
            if (i >= row_size - loop_count) {
                break;
            }
            while (i < row_size - loop_count) {
                result.push_back(matrix[i][j]);
                ++i;
            }
            --i;

            --j;
            if (j < loop_count) {
                break;
            }
            while (j >= loop_count) {
               result.push_back(matrix[i][j]);
               --j;
            }
            ++j;

            --i;
            if (i < loop_count + 1) {
                break;
            }
            while (i >= loop_count + 1) {
                result.push_back(matrix[i][j]);
                --i;
            }
            ++i;
            ++j;

            ++loop_count;
        }

        return result;
    }
};