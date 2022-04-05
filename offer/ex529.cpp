#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        if (board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int m = board.size();
        int n = board[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[click[0]][click[1]] = 1;
        q.emplace(click);
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                vector<int> c = q.front();
                q.pop();
                char ch = grid(board, c[0], c[1], m, n);
                if (ch == 'B'){
                    for (int x=c[0]-1; x<=c[0]+1; ++x){
                        for (int y=c[1]-1; y<=c[1]+1; ++y){
                            if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0){
                                vector<int> v = {x, y};
                                q.emplace(v);
                            }
                        }
                    }
                }
                board[c[0]][c[1]] = ch;
                visited[c[0]][c[1]] = 1;
            }
        }
        return board;
    }

    char grid(vector<vector<char>>& board, int i, int j, int m, int n){
        if (board[i][j] == 'M') return 'X';
        int cnt_m = 0;
        for (int x=max(i-1, 0); x<min(i+1, m); ++x){
            for (int y=max(j-1, 0); y<min(j+1, n); ++y){
                if (board[x][y] == 'M'){
                    ++cnt_m;
                }
            }
        }
        if (cnt_m == 0){
            return 'B';
        }
        return '0' + cnt_m;
    }
};

int main(){
    Solution solution;
    vector<vector<char>> board = {  {'E','E','E','E','E'},
                                    {'E','E','M','E','E'},
                                    {'E','E','E','E','E'},
                                    {'E','E','E','E','E'}
                                    };
    vector<int> click = {3, 0};
    solution.updateBoard(board, click);

    return 0;
}