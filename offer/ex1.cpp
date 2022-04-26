/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */


// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        for (int i=0; i<nums.size(); i++){
            if (visited.count(target - nums[i])){
                cout << visited[nums[i]] << " " << i << endl;
                return {visited[nums[i]], i};
            }
            visited[nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 2, 4};
    solution.twoSum(nums, 6);

    return 0;
}

// @lc code=end

