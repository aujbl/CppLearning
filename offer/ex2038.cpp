#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool winnerOfGame(string colors) {
        int len = colors.size();
        if (len < 3) return false;
        int cnt_1 = 0, cnt_2 = 0;
        int i = 0;
        char cur = colors[0];
        int cnt = 0;
        while (i < len){
            int j = i;
            while (j<len && colors[j] == cur){
                ++j;
            }
            cnt = j - i - 2;
            if (cur == 'A' && cnt > 0){
                cnt_1 += cnt;
            }else if (cur == 'B' && cnt > 0){
                cnt_2 += cnt;
            }
            if (j < len){
                cur = colors[j];
                i = j;
            }else{
                break;
            }
        }
        return cnt_1 > cnt_2;
    }
};


int main(){
    Solution solution;
    string colors({"ABBBBBBBAAA"});
    cout << solution.winnerOfGame(colors);

    return 0;
}