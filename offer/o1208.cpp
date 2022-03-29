#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> diff(n, 0);
        for (int i=0; i<n; ++i){
            diff[i] = abs(s[i] - t[i]);
        }

        int l = 0, r = 0, cost = 0;
        int ans = 0;
        while (r < n){
            cost += diff[r++];
            while (cost > maxCost){
                cost -= diff[l++];
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};

// int diff(char& a, char& b){
//     return abs(a - b);
// }

int main(int argc, char const *argv[])
{
    Solution solution;
    // string s = "abcd", t = "bcdf";
    string s = "anryddgaqpjdw";
    string t = "zjhotgdlmadcf";
    int maxCost = 5;
    
    cout << solution.equalSubstring(s, t, maxCost) << endl;
    // for (int i=0; i<4; ++i){
    //     cout << solution.diff(s[i], t[i]) << endl;
    // }

    return 0;
}
