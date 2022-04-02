#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto n : arr){
            ++cnt[n];
        }
        if (cnt[0] % 2 == 1) return false;
        sort(arr.begin(), arr.end(), [](int x, int y){return abs(x) < abs(y);});
        for (auto n : arr){
            if (cnt[2 * n] < cnt[n]) return false;
            cnt[2*n] -= cnt[n];
            cnt[n] = 0;
        }
        return true;
    }
};  

int main(int argc, char const *argv[])
{
    Solution solution;

    vector<int> arr = {2,1,2,1,1,1,2,2};

    solution.canReorderDoubled(arr);

    return 0;
}
