#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp (pair<int, int>& x, pair<int, int>& y){
        return x.second > y.second;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        
        vector<vector<int>> neiber(n, vector<int>());
        map<int, int> degrees;
        for (auto& e : edges){
            neiber[e[0]].emplace_back(e[1]);
            neiber[e[1]].emplace_back(e[0]);
            degrees[e[0]]++;
            degrees[e[1]]++;
        }

        sort(degrees.begin(), degrees.end(), cmp);

        int min_deep = n;
        vector<int> res;
        for (auto it : degrees){
            int root = it.first;
            int deep = 0;
            vector<int> visited(n, 0);
            queue<int> q;
            q.emplace(root);
            visited[root] = 1;
            int cnt = n - 1;

            while (!q.empty() && cnt > 0){
                ++deep;
                if (deep > min_deep){
                    break;
                }
                int sz = q.size();
                for (int i=0; i<sz; ++i){
                    vector<int> next = neiber[q.front()];
                    q.pop();
                    for (auto& n : next){
                        if (visited[n] == 0){
                            visited[n] = 1;
                            q.emplace(n);
                            --cnt;
                        }
                    }
                }
            }

            if (!q.empty()){
                ++deep;
            }

            if (deep == min_deep){
                res.emplace_back(root);
            }else if (deep < min_deep){
                min_deep = deep;
                res.clear();
                res.emplace_back(root);
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    int n = 4;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};

    vector<int> res = solution.findMinHeightTrees(n, edges);

    for (auto n : res){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
