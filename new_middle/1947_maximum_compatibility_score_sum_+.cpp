//
// Created by tangchao on 2022/7/6.
//

class Solution {
public:
    int compatibilityScore(const vector<int> &student, const vector<int> &mentor) {
        int m = student.size();

        int score = 0;
        for (int i = 0; i < m; ++i) {
            if (student[i] == mentor[i]) {
                ++score;
            }
        }

        return score;
    }

    int _calculate(const vector<vector<int>>& students, const vector<vector<int>>& mentors, int maskStudent, int maskMentor, vector<vector<int>> &dp) {
        int m = students.size();
        int n = students[0].size();

        if (maskStudent == ((1 << m) - 1)) {
            return 0;
        }

        if (-1 != dp[maskStudent][maskMentor]) {
            return dp[maskStudent][maskMentor];
        }

        for (int i = 0; i < m; ++i) {
            if (maskStudent & (1 << i)) {
                continue;
            }

            for (int j = 0; j < m; ++j) {
                if (0 == (maskMentor & (1 << j))) {
                    dp[maskStudent][maskMentor] = max(dp[maskStudent][maskMentor], compatibilityScore(students[i], mentors[j]) + _calculate(students, mentors, maskStudent | (1 << i), maskMentor | (1 << j), dp));
                }
            }
        }

        return dp[maskStudent][maskMentor];
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();

        vector<vector<int>> dp(1 << m, vector<int>(1 << m, -1));
        _calculate(students, mentors, 0, 0, dp);
        return dp[0][0];
    }
};