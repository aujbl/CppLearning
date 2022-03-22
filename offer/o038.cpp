#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        int j = 0;
        bool jmp = false;
        for (int i=n-2; i>=0; --i){
            j = i + 1;
            jmp = false;
            while (temperatures[j] <= temperatures[i]){
                if (res[j] > 0){
                    j += res[j];
                }else{
                    jmp = true;
                    break;
                }
            }
            if (!jmp){
                res[i] = j - i;
            }
        }
        return res;
    }
};


int main(){
    Solution solution;
    vector<int> t{73,74,75,71,69,72,76,73};

    vector<int> res;
    res = solution.dailyTemperatures(t);

    for (auto n : res){
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}









