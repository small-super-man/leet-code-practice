//
// Created by tangchao on 2022/6/3.
//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        int i = 0;
        int j = column_size - 1;
        while (i < row_size && j >= 0) {
            if (matrix[i][j] == target) {
               return true;
            }

            if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }

        return false;
    }
};