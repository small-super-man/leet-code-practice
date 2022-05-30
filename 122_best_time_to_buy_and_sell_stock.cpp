//
// Created by tangchao on 2022/5/25.
//

class Solution {
public:
    // time limit exceeded...
    /*
    int maxProfit(vector<int>& prices) {
       int prices_size = prices.size();
       vector<int> dp(prices_size, 0);
       for (int i = prices_size - 1; i >= 0; --i) {
           int max_profit = (i == prices_size - 1 ? 0 : dp[i + 1]);
           for (int j = i + 1; j < prices_size; ++j) {
              if (prices[j] > prices[i]) {
                int tmp_profit = prices[j] - prices[i];
                if (j + 1 < prices_size) {
                    tmp_profit += dp[j + 1];
                }
                if (max_profit < tmp_profit) {
                   max_profit = tmp_profit;
                }
              }
           }
           dp[i] = max_profit;
       }

       return dp[0];
    }
    */

    int maxProfit(vector<int>& prices) {
       if (prices.empty()) {
          return 0;
       }
       int profit = 0;
       int current_price = prices[0];
       for (int i = 1; i < prices.size(); ++i) {
           if (prices[i] > current_price) {
                profit += (prices[i] - current_price);
           }
           current_price = prices[i];
       }

       return profit;
    }
};