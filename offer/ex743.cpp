#include <bits/stdc++.h>

using namespace std;

class State{
public:
    int id;
    int distFromStart;
    State(int _id, int _distFromStart):id(_id), distFromStart(_distFromStart){}
};

struct cmp{
    bool operator() (const State& s1, const State& s2){
        return s1.distFromStart > s2.distFromStart;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> graph(n, vector<vector<int>>());
        buildGraph(times, graph);

        vector<int> res(n, INT_MAX);

        dijstra(k, graph, res);

        int max_len = 0;
        for (auto n : res){
            if (n == INT_MAX) return -1;
            else {
                max_len = max(max_len, n);
            }
        }
        return n;
    }

    void buildGraph(vector<vector<int>>& times, vector<vector<vector<int>>>& graph){
        for (auto& t : times){
            vector<int> tmp = {t[1] - 1, t[2]};
            graph[t[0] - 1].emplace_back(tmp);
        }
    }



    void dijstra(int start, vector<vector<vector<int>>>& graph, vector<int>& res){
        //vector<int> distTo(graph.size(), INT_MAX);
        //--start;
        res[--start] = 0;

        priority_queue<State, vector<State>, cmp> q;

        q.emplace(State (start, 0));

        while (!q.empty()){
            State s = q.top();
            q.pop();
            int cur_id = s.id;
            int cur_distFromStart = s.distFromStart;

            if (cur_distFromStart > res[cur_id]){
                continue;
            }

            for (auto& next : graph[cur_id]){
                int next_id = next[0];
                int distToNextNode = res[cur_id] + next[1];

                if (res[next_id] > distToNextNode){
                    res[next_id] = distToNextNode;
                    q.emplace(State (next_id, distToNextNode));
                }
            }
        }

        
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    solution.networkDelayTime(times, n, k);

    return 0;
}
