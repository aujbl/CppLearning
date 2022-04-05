#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n = 0;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = beginWord.size();
        if (count(wordList.begin(), wordList.end(), endWord) == 0) return 0;
        //int step = count(wordList.begin(), wordList.end(), beginWord);
        int step = 0;

        queue<string> q;
        unordered_set<string> visited;
        q.emplace(beginWord);
        visited.emplace(beginWord);
        while (!q.empty()){
            int sz = q.size();
            string s = q.front();
            q.pop();
            for (int i=0; i<sz; ++i){
                for (auto& w : wordList){
                    if (minus(s, w)){           
                        if (w == endWord){
                            return ++step;
                        };
                        if (visited.count(w) == 0){
                            q.emplace(w);
                            visited.emplace(w);
                        }
                    }
                }
            }
            ++step;
        }
        return 0;
    }

    bool minus(string s1, string s2){
        int cnt = 0;
        for (int i=0; i<n; ++i){
            if (s1[i] != s2[i]){
                ++cnt;
            }
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }


};

int main(){
    Solution solution;
    string beginWord = "hot";
    string endWord = "dog";
    vector<string> wordList = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    solution.ladderLength(beginWord, endWord, wordList);

    return 0;
}