#include<bits/stdc++.h>
using namespace std;

class P
{
public:
    P(int xx=0){X = xx;}
    
    static void show(P &q){cout << q.X;};

private:
    int X;
};


int main(){
    P A(5);
    P B(A);
    P::show(B);
    return 0;
}