#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int odds = 0, i = 0, j = 0;
        int cnt = 0;
        while (j < n && odds < k){
            if (nums[i] % 2 == 1){
                ++odds;
            }
            while (i < n && odds >= k){
                if (odds == k){
                    ++cnt;
                }
                if (nums[i] % 2 == 1){
                    --odds;
                }
                ++i;
            }
            ++j;
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;

    solution.numberOfSubarrays(nums, k);

    return 0;
}
