#include <bits/stdc++.h>

using namespace std;


// class Solution {
// public:
//     int minimumDeleteSum(string s1, string s2) {
//         int m = s1.size(), n = s2.size();
//         vector<int> dp(m+1, 0);
//         vector<int> new_dp = dp;

//         for (int j=0; j<n; j++){
//             for (int i=1; i<=m; i++){
//                 if (s2[j] == s1[i-1]){
//                     new_dp[i] = max(dp[i-1]+1, max(new_dp[i-1], dp[i]));            
//                 }
//                 else{
//                     new_dp[i] = max(dp[i], new_dp[i-1]);
//                 }
//             }
//             dp = new_dp;
//             print(dp);
//         }

//         return dp[m];
//     }

    
//     void print(const vector<int>& dp){
//         for (auto n : dp){
//             cout << n << " ";
//         }
//         cout << endl;
//     }
// };

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> dp(m+1, 0);
        vector<int> new_dp = dp;

        for (int j=0; j<n; j++){
            for (int i=1; i<=m; i++){
                if (s2[j] == s1[i-1]){
                    new_dp[i] = max(dp[i-1]+1, max(new_dp[i-1], dp[i]));            
                }
                else{
                    new_dp[i] = max(dp[i], new_dp[i-1]);
                }
            }
            dp = new_dp;
            print(dp);
        }
        int repeat = 0;
        for (int i=1; i<=m; i++){
            if (dp[i] > dp[i-1]){
                cout << "i: " << i << " " << s1[i-1] << " ";
                repeat += (int)s1[i-1];
            }
        }
        int res = 0;
        for (auto c : s1){
            res += (int)c;
        }
        for (auto c : s2){
            res += (int)c;
        }

        return res - repeat - repeat;
    }

        
    void print(const vector<int>& dp){
        for (auto n : dp){
            cout << n << " ";
        }
        cout << endl;
    }
};


int main(int argc, char const *argv[])
{
    Solution solution;
    solution.minimumDeleteSum("delete", "leet");

    return 0;
}
