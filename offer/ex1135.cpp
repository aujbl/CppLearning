#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> mytp;

struct cmp{
    bool operator() (const mytp& a, const mytp& b){
        return a.second > b.second;
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<vector<mytp>> edges(n, vector<mytp>());
        calEdges(connections, edges);
        priority_queue<mytp, vector<mytp>, cmp > q;
        q.emplace(mytp (0, 0));
        vector<int> visited(n, 0);

        int cost = 0;
        while(!q.empty()){
            int to = q.top().first, c = q.top().second;
            q.pop();

            if (visited[to] == 0){
                cost += c;
                visited[to] = 1;
            }

            if (allVisited(visited)) break;
            
            for (auto& next : edges[to]){
                if (visited[next.first] == 0){
                    q.emplace(next);
                }
            }

        }
    
        return allVisited(visited) ? cost : -1;
    }

    bool allVisited(vector<int>& v){
        for (auto& b:v){
            if (!b) return false;
        }
        return true;
    }

    void calEdges(vector<vector<int>>& connections, vector<vector<mytp>>& edges){
        for (auto& c : connections){
            mytp a(c[0] - 1, c[2]);
            mytp b(c[1] - 1, c[2]);
            edges[c[0] - 1].emplace_back(b);
            edges[c[1] - 1].emplace_back(a);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    // solution

    return 0;
}
