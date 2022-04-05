#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while (l <= r){
            mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }else if (target >= nums[l] && target < nums[mid]){
                r = mid - 1;
            }else{
                l = mid;
            }
        }    
        return l;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {5,1,3};
    int target = 5;
    solution.search(nums, target);

    return 0;
}