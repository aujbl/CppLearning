#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> mytyp;

struct cmp{
    bool operator() (const mytyp& t1, const mytyp& t2){
        return t1.second > t2.second;
    }
};


int main(int argc, char const *argv[])
{
    priority_queue<mytyp, vector<mytyp>, cmp > q;

    mytyp b(1, 2);
    mytyp c(1, 3);
    mytyp d(2, 5);
    mytyp e(2, 2);

    q.emplace(b);
    q.emplace(c);
    q.emplace(d);
    q.emplace(e);

    while (!q.empty()){
        cout << q.top().first << " " << q.top().second << endl;
        q.pop();
    }

    return 0;
}
