#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        for (int i=0; i<n; i++){
            if (i-1 == -1){
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }

        return dp[n-1][0];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    solution.maxProfit(prices);

    return 0;
}
