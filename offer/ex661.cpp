#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res = img;
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                int total = 0;
                int u = max(0, i-1), d = min(i+1, m-1);
                int l = max(j-1, 0), r = min(j+1, n-1);
                int cnt = 0;
                for (int a=u; a<=d; ++a){
                    for (int b=l; b<=r; ++b){
                        total += img[a][b];
                        ++cnt;
                    }
                }
                img[i][j] = total/cnt;
            }
        }
        return img;
    }
};


int main(){
    Solution solution;
    vector<vector<int>> img = {{100,200,100},{200,50,200},{100,200,100}};

    solution.imageSmoother(img);
}