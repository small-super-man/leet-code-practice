//
// Created by tangchao on 2022/5/23.
//

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       unordered_set<int> row_set;
       unordered_set<int> column_set;
       int row_size = matrix.size();
       int column_size = matrix[0].size();
       for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < column_size; ++j) {
                if (0 == matrix[i][j]) {
                    row_set.insert(i);
                    column_set.insert(j);
                }
            }
       }

       for (auto iter = row_set.begin(); iter != row_set.end(); ++iter) {
            for (int i = 0; i < column_size; ++i) {
               matrix[*iter][i] = 0;
            }
       }

       for (auto iter = column_set.begin(); iter != column_set.end(); ++iter) {
            for (int i = 0; i < row_size; ++i) {
                matrix[i][*iter] = 0;
            }
       }
    }
};