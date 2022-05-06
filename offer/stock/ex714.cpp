#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2));
        // dp[0][0] = 0, dp[0][1] = -prices[0]-fee;
        // for(int i=1; i<n; i++){
        //     dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
        //     dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]-fee);
        // }

        // return dp[n-1][0];

        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0] - fee;
        for (int i=1; i<n; i++){
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1, tmp - prices[i] - fee);
        }

        return dp_i_0;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution solution;
//     solution

//     return 0;
// }
