#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs){
            m[strsToKey(s)].push_back(s);
        }

        vector<vector<string>> res;
        for (auto it : m){
            res.push_back(it.second);
        }
        return res;
    }

    string strsToKey(string& s){
        if (s == ""){
            return " ";
        }

        vector<int> cnt(26, 0);
        for (auto ch : s){
            cnt[ch - 'a']++;
        }
        string res = "";
        for (int n : cnt){
            res += to_string(n);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> strs = {"bdddddddddd","bbbbbbbbbbc"};
    solution.groupAnagrams(strs);

    return 0;
}
