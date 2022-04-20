#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n < 2){
            return n;
        }
        unordered_set<char> occ;
        int r = -1, res = 1;
        for (int i=0; i<n; i++){
            if (i > 0){
                occ.erase(s[i]);
            }


            while (r + 1 < n && occ.count(s[r + 1]) == 0){
                occ.emplace(s[r+1]);
                r++;
            }

            res = max(res, r - i + 1);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.lengthOfLongestSubstring("pwwkew");

    return 0;
}
