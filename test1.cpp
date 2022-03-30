#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int m, n;

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<int> dirs = {1, 0, -1, 0, 1};
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int cnt = 0;
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if ((grid[i][j] == '1') && (visited[i][j] == 0)){
                    ++cnt;
                    dfs(grid, dirs, visited, i, j);
                }else{
                    visited[i][j] = 1;
                }
            }
        }

        return cnt;
    }

    void dfs(vector<vector<char>>& grid, vector<int>& dirs, vector<vector<int>>& visited, int i, int j){
        queue<vector<int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty()){
            vector<int> tmp = q.front();    
            q.pop();
            int x = tmp[0], y = tmp[1];
            for (int k=0; k<4; ++k){
                int x1 = x + dirs[k], y1 = y + dirs[k+1];
                if ((x1 >=0 && x1 < m) && (y1 >= 0 && y1 < n) && (grid[x1][y1] == '1') && (visited[x1][y1] == 0)){
                    visited[x1][y1] = 1;
                    q.push({x1, y1});
                }
            }
        }
    }

};




int main(int argc, char const *argv[])
{
    Solution solution;

    vector<vector<char>> grid = {{'1', '2', '3'}, {'4', '5', '6'}};

    solution.numIslands(grid);

    return 0;
}
