#include <bits/stdc++.h>
using namespace std;

class UF{
private:
    int cnt;
    vector<int> parent;
public:
    UF(int n){
        cnt = n;
        parent.resize(cnt);
        for (int i=0; i<cnt; ++i){
            parent[i] = i;
        }
    };

    void _union(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        --cnt;
        return;
    };

    bool isconnect(int p, int q){
        return find(p) == find(q);
    };

    int find(int x){
        while (parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };

    int count(){
        return cnt;
    };
}