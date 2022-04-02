#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string new_s = "#";
        for (int i=0; i<n; ++i){
            new_s += s[i]; 
            new_s += "#";
        }

        string res;
        vector<int> idx(2);
        int max_len = 0;
        n = new_s.size();
        for (int i=0; i<n; ++i){
            palindrome(new_s, idx, i, n);
            int len = idx[1] - idx[0] + 1;
            if (len > max_len){
                max_len = len;
                res = new_s.substr(idx[0], len);
            }
        }
        string ans;
        for (int i=0; i<res.size(); ++i){
            if (res[i] != '#') 
                ans += res[i];
        }
        return ans;
    }

    void palindrome(string& s, vector<int>& idx, int i, int n){
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]){
            --l;
            ++r;
        }
        idx[0] = max(0, l + 1);
        idx[1] = min(n-1, r - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "cbbd";
    cout << solution.longestPalindrome(s) << endl;

    return 0;
}
