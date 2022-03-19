#include <bits/stdc++.h>

using namespace std;

// #include <unordered_map>
// #include <string>
// #include <vector>
// #include <cmath>


class Solution {
private:
    unordered_map<char, int> myorder;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        setorder(order);
        int len = words.size();
        for (int i=0; i<len-1; ++i){
            if (!cmp(words[i], words[i+1])){
                return false;
            }
        }
        return true;
    }

    bool cmp(const string &w1, const string &w2){
        int len = min(w1.size(), w2.size());
        for (int i=0; i<len; ++i){
            if (myorder[w1[i]] < myorder[w2[i]]){
                return true;
            }else if (myorder[w1[i]] > myorder[w2[i]]){
                return false;
            }
        }
        return w1.size() <= w2.size();
    }

    void setorder(const string &order){
        int len = order.size();
        for (int i=0; i<len; ++i){
            myorder[order[i]] = i;
        }
    }
};


int main(){
    Solution solution;
    vector<string> words({"ubg","kwh"});

    string order("qcipyamwvdjtesbghlorufnkzx");

    cout << solution.isAlienSorted(words, order) << endl;;

    return 0;
}