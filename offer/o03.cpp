#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        unordered_set<char> occ;
        occ.insert(s[0]);
        int j = 1, ans = 1;
        for (int i=0; i<n; ++i){
            while (j < n && occ.count(s[j]) == 0){
                occ.insert(s[j]);
                ++j;
            }
            ans = max(ans, j - i);
            occ.erase(s[i]);
        }
        return ans;
    }
};      

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "abcabcbb"; 

    solution.lengthOfLongestSubstring(s);

    return 0;
}
