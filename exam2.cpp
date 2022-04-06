#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    cin.get();

    vector<vector<int>> graph(n);
    
    string s;
    int num = 0;
    string tmp;
    for (int i=0; i<n; ++i){
        s.clear();
        getline(cin, s);
        tmp.clear();
        vector<int> vec;
        for (auto ch : s){
            if (ch == ','){
                num = stoi(tmp);
                vec.emplace_back(num);
                tmp.clear();
            }else{
                tmp += ch;
            }
        }
        num = atoi(tmp.c_str());
        vec.emplace_back(num);
        tmp.clear();
        for (int k=0; k<vec[0]; ++k){
            graph[i].emplace_back(vec[k+1]);
        }
        vec.clear();
    }

    vector<int> onPath(n, 0);
    vector<int> visited(n, 0);
    bool hasCircle = false;

    queue<int> q;
    for (auto n:graph[m]){
        q.emplace(n);
        onPath[n] = 1;
    }
    //visited[m] = 1;
    
    while (!q.empty()){
        int sz = q.size();
        for (int i=0; i<sz; ++i){
            int p = q.front();
            q.pop();
            for (auto n : graph[p]){
                if (onPath[n] == 1){
                    hasCircle = true;
                    break;
                }else{
                    if (visited[n] == 0){
                        onPath[n] = 1;
                        q.emplace(n);
                        visited[n] = 1;
                    }
                }
            }
            if (hasCircle){
                break;
            }
        }
    }

    string res = "";
    if (hasCircle){
        cout << -1 << endl;
        return 0;
    }else{
        for (int i=0; i<n; ++i){
            if (i == m){
                continue;
            }
            if (onPath[i]){
                res += to_string(i) + ",";
            }
        }
    }
    res.erase(res.end()-1);
    cout << res << endl;

    // for (int i=0; i<n; ++i){
    //     for (auto num : graph[i]){
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
