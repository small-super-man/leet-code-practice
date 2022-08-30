class Solution {
public:
    // currentSum <= (touch + 1) * aimedSum;

    bool dpFunc(vector<int>& matchsticks, int mask, int touch, int currentSum, int aimedSum,
            map<pair<int, int>, bool>& memo)
    {
        if (touch>=3) {
            return true;
        }

        pair<int, int> key(mask, touch);
        if (memo.count(key)) {
            return memo[key];
        }


        if (currentSum==(touch+1)*aimedSum) {
            bool ret = dpFunc(matchsticks, mask, touch+1, currentSum, aimedSum, memo);
            memo[key] = ret;
            return ret;
        }

        for (int i = 0; i < matchsticks.size(); ++i) {
            if ((mask & (1 << i)) == 0 && (currentSum + matchsticks[i] <= (touch + 1) * aimedSum)) {
                bool ret = dpFunc(matchsticks, mask | (1 << i), touch, currentSum + matchsticks[i], aimedSum, memo);
                if (ret) {
                    memo[key] = true;
                    return true;
                }
            }
        }

        memo[key] = false;
        return false;
    }

    bool makesquare(vector<int>& matchsticks)
    {
        map<pair<int, int>, bool> memo;

        int total_sum = 0;
        for (auto& e: matchsticks) {
            total_sum += e;
        }

        if (total_sum % 4) {
            return false;
        }

        int aimed_sum = total_sum / 4;

        return dpFunc(matchsticks, 0, 0, 0, aimed_sum, memo);
    }

};