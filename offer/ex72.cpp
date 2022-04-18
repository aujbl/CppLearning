#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(m+1);
        for (int i=0; i<=m; i++){
            dp[i] = i;
        }
        vector<int> new_dp = dp;
        for (int j=0; j<n; j++){
            for (int i=1; i<=m; i++){
                if (word1[i-1] == word2[j]){
                    new_dp[i] = min(min(dp[i-1], dp[i]), new_dp[i-1]);
                }else{
                    new_dp[i] = min(min(dp[i-1], dp[i]), new_dp[i-1]) + 1;
                }
            }
            new_dp[0] = j + 1;
            dp = new_dp;
        }
        
        return dp[m];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s1 = "zoologicoarchaeologist";
    string s2 = "zoogeologist";
    solution.minDistance(s1, s2);

    return 0;
}
