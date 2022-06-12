#include <bits/stdc++.h>
using namespace std;
// #include <vector>

class Solution {
private:
    int m, n;
    int res = INT_MAX;
    
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m = grid.size(), n = grid[0].size();
        dfs(grid, moveCost, 0, -1, 0);
        
        return res;
    }
    
    void dfs(const vector<vector<int>>& grid, const vector<vector<int>>& moveCost, int i, int val, int cost){
        if (i == m){
            res = min(res, cost);
            return;
        }
        for (int k=0; k<n; ++k){
            cost += grid[i][k];
            if (val >= 0 && val < m*n){
                cost += moveCost[val][k];
            }
            dfs(grid, moveCost, i+1, grid[i][k], cost);
        }
    }
};


int main(){
    Solution s;
    vector<vector<int>> grid = {{5, 3}, {4, 0}, {2, 1}};
    vector<vector<int>> moveCost = {{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};

    s.minPathCost(grid, moveCost);
}