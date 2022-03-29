#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        int l = 0, r = 0;
        while (r < n){
            sum += nums[r];
            while (sum - nums[l] >= target){
                sum -= nums[l];
                ++l;
            }
            if (sum >= target){
                
                ans = min(ans, r - l + 1);
            }
            ++r;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout << solution.minSubArrayLen(target, nums) << endl;

    return 0;
}
