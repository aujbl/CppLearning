#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;

        queue<string> q;
        unordered_set<string> visited;
        q.emplace("0000");
        visited.emplace("0000");
        int step = 0;
        char ch, ch1, ch2;
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                string s = q.front();
                q.pop();
                for (int j=0; j<4; ++j){
                    ch = s[j];
                    if (ch == '0'){
                        ch1 = '9'; ch2 = '1';
                    }else if (ch == '9'){
                        ch1 = '8'; ch2 = '0';
                    }else {
                        ch1 = ch - 1; ch2 = ch + 1;
                    }
                    s[j] = ch1;
                    if (s == target){
                        return ++step;
                    }else if (visited.count(s) == 0 && count(deadends.begin(), deadends.end(), s) == 0){
                        q.emplace(s);
                        visited.emplace(s);
                    }
                    s[j] = ch2;
                    if (s == target){
                        return ++step;
                    }else if (visited.count(s) == 0 && count(deadends.begin(), deadends.end(), s) == 0){
                        q.emplace(s);
                        visited.emplace(s);
                    }
                    s[j] = ch;
                }
            }
            step++;
        }
        return -1;
    }
};

int main(){
    Solution solution;
    //vector<int> nums = {};
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    solution.openLock(deadends, target);

    return 0;
}