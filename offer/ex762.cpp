#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> prime = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int cnt = 0;
        for (int i=left; i<=right; ++i){
            int j = i, numBits = 0;
            while (j){
                numBits += (j & 1);
                j >>= 1;
            }
            if (prime.count(numBits)){
                ++cnt;
                cout << "i: " << i << " numBits: " << numBits << endl;
            }
        }
        return cnt;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {};
    solution.countPrimeSetBits(6, 10);

    return 0;
}