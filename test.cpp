#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    s = "assssa";
    // while (cin >> s){
        vector<int> cnt(26, 0);
        int min_oc = INT_MAX;
        for (auto ch : s){
            cnt[ch - 'a']++;
            min_oc = min(min_oc, cnt[ch - 'a']);
        }
        for (auto ch : s){
            if (cnt[ch - 'a'] == min_oc){
                continue;
            }
            cout << ch;
        }
        cout << endl;
        // s.clear();
    // }
        
    
    return 0;
}