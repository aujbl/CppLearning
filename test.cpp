#include <bits/stdc++.h>

using namespace std;

#include<algorithm>

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bands;
        unordered_map<string, int> cnt;
        for (auto s : banned){
            bands.emplace(s);
        }
        int max_cnt = 0;
        string res;
        string tmp;
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        for (auto c : paragraph){
            if (c >= 'a' && c <= 'z'){
                tmp += c;
            }else{
                if (tmp.size() > 0){
                    cnt[tmp] += 1;
                    if (cnt[tmp] > max_cnt){
                        max_cnt = cnt[tmp];
                        res = tmp;
                    }
                }
                tmp.clear();
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";   
    vector<string> banned = {"hit"};

    if (argc <= 1){
        cout << "argc <= 1" << endl;
    }else{
        cout << "argc > 1" << endl;
    }

    solution.mostCommonWord(paragraph, banned);

    return 0;
}


