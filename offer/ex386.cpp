#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        dfs(res, 1, n);
        return res;
    }

    void dfs(vector<int>& res, int start, int n){
        if (start > n){
            return;
        }
        res.emplace_back(start);
        for (int i=0; i<10; i++){
            dfs(res, start*10 + i, n);
        }
        return;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.lexicalOrder(13);

    return 0;
}
