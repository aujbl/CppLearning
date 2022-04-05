#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string b = "";
        string target = "123450";
        for (int i=0; i<2; ++i){
            for (int j=0; j<3; ++j){
                b += board[i][j];
            }
        }
        if (b == target) return 0;

        vector<vector<int>> change = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<string> q;
        q.emplace(b);
        int step = 0;
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                string s = q.front();
                q.pop();

                for (int j=0; j<6; ++j){
                    if (s[j] != '0'){
                        continue;
                    }
                    vector<int> move = change[j];
                    for (int m : move){
                        string tmp = s;
                        swap(tmp[j], tmp[m]);
                        if (tmp == target) return ++step;
                        q.emplace(tmp);
                    }
                }

            }
            ++step;
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> nums = {{1, 2, 3},{4, 0, 5}};
    solution.slidingPuzzle(nums);

    return 0;
}