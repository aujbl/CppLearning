#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator() (const vector<int>& v1, const vector<int>& v2){
        return v1[2] > v2[2];
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        calEdges(points, edges);

        priority_queue<vector<int>, vector<vector<int>>, cmp > q;
        for (auto& e : edges){
            q.emplace(e);
        }

        while (!q.empty()){
            vector<int> tmp = q.top();
            q.pop();
            cout << "i: " << tmp[0] << " j: " << tmp[1] << " distance: " << tmp[2] << endl;
        }
        

        return 0;
    }

    void calEdges(vector<vector<int>>& points, vector<vector<int>>& edges){
        int n = points.size();
        for (int i=0; i<n; ++i){
            for (int j=i+1; j<n; ++j){
                vector<int> tmp = {i, j, distance(points[i], points[j])};
                edges.emplace_back(tmp);
            }
        }
    }

    int distance(vector<int>& v1, vector<int>& v2){
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
};


int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    solution.minCostConnectPoints(points);
    // solution

    return 0;
}
