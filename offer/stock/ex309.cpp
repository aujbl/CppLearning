#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;

        // vector<vector<int>> dp(n, vector<int>(2));
        // dp[0][0] = 0;
        // dp[0][1] = -prices[0];
        // dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        // dp[1][1] = max(dp[0][1], - prices[1]);
        // for (int i=2; i<n; i++){
        //     dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //     dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        // }

        // return dp[n-1][0];

        int dp_i_0 = 0, dp_i_1 = -prices[0];
        int dp_i_0_prev = 0;
        for (int i=1; i<n; i++){
            if (i == 1){
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                dp_i_1 = max(dp_i_1, -prices[i]);
            }else{
                int tmp = dp_i_0;
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                dp_i_1 = max(dp_i_1, dp_i_0_prev - prices[i]);
                dp_i_0_prev = tmp;
            }
        }

        return dp_i_0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> prices = {1,2,4};
    solution.maxProfit(prices);

    return 0;
}
