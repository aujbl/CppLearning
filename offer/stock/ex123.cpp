#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));
        // for (int i=0; i<n; i++){
        //     for (int j=1; j<3; j++){
        //         if (i == 0){
        //             dp[i][j][0] = 0;
        //             dp[i][j][1] = -prices[i];
        //             continue;
        //         }
        //         dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
        //         dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                
        //     }
        // }
        // return dp[n-1][2][0];

        int n = prices.size();
        int dp_i_10 = 0, dp_i_11 = -prices[0];
        int dp_i_20 = 0, dp_i_21 = -prices[0];
        for (int i=1; i<n; i++){
            dp_i_20 = max(dp_i_20, dp_i_21 + prices[i]);
            dp_i_21 = max(dp_i_21, dp_i_10 - prices[i]);
            dp_i_10 = max(dp_i_10, dp_i_11 + prices[i]);
            dp_i_11 = max(dp_i_11, -prices[i]);
        }

        return dp_i_20;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution solution;
//     solution

//     return 0;
// }
